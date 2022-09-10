#!/usr/bin/env python3
import sys
from PySide2 import QtWidgets, QtGui

#from selfdrive.ui.qt.python_helpers import set_main_window


if __name__ == "__main__":
  app = QtWidgets.QApplication([])

  label = QtWidgets.QLabel('Hello World!')
  label.show()

  # Set full screen and rotate
  #set_main_window(label)

  sys.exit(app.exec_())
