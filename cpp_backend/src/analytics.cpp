#include "analytics.hpp"

/**
 * @brief Calculate VAT
 * @param amount The amount
 * @param rate The rate
 * @return amount * rate
 **/
namespace Analytics {
  double CalculateVAT(double amount, double rate) {
    return amount * rate;
}

    double Mean(const std::vector<double>& values) {
      double sum = 0.0;
      for (auto v : values) sum += v;
      return values.empty() ? 0.0 : sum / values.size();
    }
};

