from distutils.core import setup, Extension

kinematics = Extension("_kinematics", ["_kinematics_module.cc", "kinematics.c"])

setup(name = "kinematics", ext_modules=[kinematics])