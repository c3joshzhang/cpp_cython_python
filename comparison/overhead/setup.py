from setuptools import setup, find_packages, Extension
from Cython.Build import cythonize

ext_module = Extension(
	"cpplib", # the module name exposed to python
    ["Example.cpp", "PyAdapterCpp.pyx"], # the files required for compile
    language="c++",
    extra_compile_args=["-std=c++11", "-fopenmp", "-O3"],
    extra_link_args=["-std=c++11", "-fopenmp"]
)

setup(ext_modules=cythonize(ext_module))
