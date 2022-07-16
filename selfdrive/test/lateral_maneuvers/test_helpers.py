import numpy as np
import cereal.messaging as messaging
from selfdrive.modeld.constants import T_IDXS
from selfdrive.controls.lib.drive_helpers import LAT_MPC_N as N
from selfdrive.controls.lib.lateral_planner import LateralPlanner


class Plan:
  def __init__(self, speed, yaw_rate, y_offset, current_yaw_rate):
    self.speed = speed
    self.yaw_rate = np.radians(yaw_rate)
    self.y_offset = y_offset
    self.current_yaw_rate = np.radians(current_yaw_rate)
    self.dt = np.diff(T_IDXS, prepend=0.0)

  def get_plan_pts(self):
    plan_trajectory = {}
    yaw = np.cumsum(self.dt * self.yaw_rate)
    plan_trajectory['position'] = np.zeros((len(T_IDXS), 3))
    plan_trajectory['orientation'] = np.zeros((len(T_IDXS), 3))
    plan_trajectory['position'][:, 0] = np.cumsum(np.cos(yaw) * self.speed * self.dt)
    plan_trajectory['position'][:, 1] = np.cumsum(np.sin(yaw) * self.speed * self.dt) + self.y_offset
    plan_trajectory['orientation'][:, 2] = yaw
    return plan_trajectory

  def put_vals(self, modelV2, plan, field):
    submsg = modelV2.__getattr__(field)
    vals = plan[field] if field in plan else np.zeros_like(plan['position'])
    stds = np.ones_like(plan['position'])
    submsg.t = T_IDXS
    submsg.x = vals[:, 0].tolist()
    submsg.y = vals[:, 1].tolist()
    submsg.z = vals[:, 2].tolist()
    submsg.xStd = stds[:, 0].tolist()
    submsg.yStd = stds[:, 1].tolist()
    submsg.zStd = stds[:, 2].tolist()

  def get_messages(self):
    plan = self.get_plan_pts()
    sm = {}
    for message in ['carState', 'controlsState', 'modelV2']:
      sm[message] = messaging.new_message(message).__getattr__(message)

    sm['carState'].vEgo = self.speed
    sm['controlsState'].active = True
    sm['controlsState'].curvature = float(self.current_yaw_rate / max(1.0, self.speed))

    for field in ['position', 'velocity', 'orientation', 'orientationRate']:
      self.put_vals(sm['modelV2'], plan, field)

    return sm

  def run_planner(self):
    plan_points = self.get_plan_pts()
    sm = self.get_messages()
    lp = LateralPlanner(use_lanelines=False)
    lp.x0[3] = sm['controlsState'].curvature
    lp.update(sm)

    y_err = lp.lat_mpc.x_sol[:, 1] - plan_points['position'][:N + 1, 1]
    lateral_acceleration = lp.lat_mpc.x_sol[:, 3] * self.speed**2
    return y_err, lateral_acceleration
