#!/usr/bin/env python3
import unittest
from selfdrive.test.lateral_maneuvers.test_helpers import Plan, run_planner


class LateralPlannerSingleStepTests(unittest.TestCase):
  """
  Currently we only have single step tests.
  Ideally we should have full trajectories, but that requires a simple simulator (dynamics) and
  re-calculating the plan wrt ground-truth at each step like in xx.
  """
  def straight_road(self):
    sm = Plan(speed=30, yaw_rate=3, y_offset=0, current_yaw_rate=0).get_messages()
    planner_result = run_planner(sm)
    self.assertTrue(planner_result)


if __name__ == "__main__":
  unittest.main(failfast=True)
