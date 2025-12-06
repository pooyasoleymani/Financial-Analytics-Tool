#pragma once
#include <vector>

namespace Analytics {
  double CalculateVAT(double amount, double rate);
  double Mean(const std::vector<double>& values);
}
