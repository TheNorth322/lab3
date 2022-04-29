#include "commission_wage_worker.h"

CommissionWageWorker::CommissionWageWorker(std::string _fullName,
                                           Gender _gender, int _salary,
                                           int _percentage)
    : fullName(_fullName), gender(_gender), salary(_salary),
      percentage(_percentage) {
  goodsSoldSum = 0;

  if (fullName.length() == 0) {
    throw std::invalid_argument(
        "Invalid 'fullName' argument. The length must be non-zero.");
  }

  if (salary <= 0) {
    throw std::invalid_argument("Invalid 'salary' argument. "
                                "Value must be greater than zero.");
  }

  if (percentage <= 0) {
    throw std::invalid_argument(
        "Invalid 'percentage' argument. "
        "Value must be greater than zero and less than 100.");
  }
}

void CommissionWageWorker::setFullName(const std::string fn) { fullName = fn; }

std::string CommissionWageWorker::getFullName() { return fullName; }

void CommissionWageWorker::setGender(const Gender g) { gender = g; }

void CommissionWageWorker::setSalary(const int s) { salary = s; }

void CommissionWageWorker::setPercentage(const int p) { percentage = p; }

void CommissionWageWorker::sell(int goodsSold) { goodsSoldSum += goodsSold; }

int CommissionWageWorker::calcWage() {
  int addition = (int)((float)goodsSoldSum * (float)(percentage) / 100.);
  int wage = salary + addition;

  goodsSoldSum = 0;

  return wage;
}
