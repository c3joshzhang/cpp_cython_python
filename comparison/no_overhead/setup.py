from setuptools import setup, find_packages, Extension
from Cython.Build import cythonize
import numpy

ext_module = Extension(
	"cpplib", # the module name exposed to python
    ["Example.cpp", "PyAdapterCpp.pyx"], # the files required for compile
    language="c++",
    extra_compile_args=["-std=c++11", "-fopenmp", "-O3"],
    extra_link_args=["-std=c++11", "-fopenmp"],
    include_dirs=[numpy.get_include()]
)

setup(ext_modules=cythonize(ext_module))
