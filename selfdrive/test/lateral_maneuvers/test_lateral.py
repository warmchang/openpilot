#!/usr/bin/env python3
import unittest
import numpy as np
from selfdrive.test.lateral_maneuvers.test_helpers import Plan

Y_ERR_THRESH = 1  # m
Y_ERR_THRESH_END = 0.5  # m
LA_ERR_THRESH = 3.0  # m/s^2


class LateralPlannerSingleStepTests(unittest.TestCase):
  """
  Note:
  1. Currently we only have single step tests. Ideally we should have full trajectories,
  but that requires a simple simulator (dynamics) and re-calculating the plan wrt
  ground-truth at each step like in xx.
  2. The generated plan right now is very simple, and does not account for the variation
  in rotation radius in cars.
  Todo: Add some actual trajectories

  """
  def check_all_asserts(self, args):
    y_err, lat_acc = args
    self.assertTrue(np.max(np.abs(y_err)) < Y_ERR_THRESH)
    self.assertTrue(np.abs(y_err[-1]) < Y_ERR_THRESH_END)
    self.assertTrue(np.max(np.abs(lat_acc)) < LA_ERR_THRESH)

  def test_straight_road(self):
    plan = Plan(speed=30, yaw_rate=0, y_offset=0, current_yaw_rate=0)
    self.check_all_asserts(plan.run_planner())

  def test_straight_road_offset(self):
    plan = Plan(speed=30, yaw_rate=0, y_offset=0.5, current_yaw_rate=0)
    self.check_all_asserts(plan.run_planner())

  def test_high_speed_turn(self):
    plan = Plan(speed=30, yaw_rate=3, y_offset=0, current_yaw_rate=0)
    self.check_all_asserts(plan.run_planner())

  def test_low_speed_turn(self):
    plan = Plan(speed=5, yaw_rate=3, y_offset=0, current_yaw_rate=0)
    self.check_all_asserts(plan.run_planner())

  def test_offset_turn(self):
    plan = Plan(speed=5, yaw_rate=3, y_offset=-0.5, current_yaw_rate=0)
    self.check_all_asserts(plan.run_planner())

  def test_sharp_turn(self):
    plan = Plan(speed=10, yaw_rate=-10, y_offset=0, current_yaw_rate=0)
    self.check_all_asserts(plan.run_planner())

  def test_sharp_turn_already_turning(self):
    plan = Plan(speed=10, yaw_rate=-10, y_offset=0, current_yaw_rate=-5)
    self.check_all_asserts(plan.run_planner())

  def test_sharp_turn_already_turning_offset(self):
    plan = Plan(speed=10, yaw_rate=-10, y_offset=0.5, current_yaw_rate=-5)
    self.check_all_asserts(plan.run_planner())


if __name__ == "__main__":
  unittest.main(failfast=True)
