#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "analytics.hpp"

namespace py = pybind11;

PYBIND11_MODULE(finanalytics, m) {
    m.doc() = "Financial analytics C++ backend exposed to Python";
    m.def("CalculateVAT", &Analytics::CalculateVAT, "Calculate VAT");
    m.def("Mean", &Analytics::Mean, "Compute mean of values");
}
