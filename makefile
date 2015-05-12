all:
	swig -python -c++ -o _kinematics_module.cc swig.i
	python setup.py build_ext --inplace