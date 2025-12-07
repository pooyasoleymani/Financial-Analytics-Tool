from setuptools import setup, Extension
import pybind11

ext_modules = [
    Extension(
        "finanalytics",
        ["bindings/pybind_module.cpp", "cpp_backend/src/analytics.cpp"],
        include_dirs=["cpp_backend/include", pybind11.get_include()],
        language="c++"
    )
]

setup(
    name="finanalytics",
    version="1.0.0",
    description="Financial analytics tool with C++ backend and PyQt5 frontend",
    ext_modules=ext_modules,
    install_requires=["PyQt5"],
)
