from setuptools import setup, find_packages, Extension
from Cython.Build import cythonize
import numpy

ext_module = Extension(
	"cpplib", # the module name exposed to python
    ["./ccp_ext/ServiceCost.cpp", "./ccp_ext/PyAdapterCpp.pyx"], # the files required for compile
    language="c++",
    extra_compile_args=["-std=c++11", "-fopenmp"],
    extra_link_args=["-std=c++11", "-fopenmp"],
    include_dirs=[numpy.get_include()]
)

setup(
	name="ccp_ext",
    version="0.0.0",
    author="Josh Zhang",
    description="Example for intergrating C++ and Python",
    long_description_content_type="text/markdown",
    packages=find_packages(),
    python_requires='>=3.5',
    ext_modules=cythonize(ext_module))
