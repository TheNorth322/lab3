#pragma once

#include "common.h"
#include <iostream>
#include <stdexcept>
#include <string>

class CommissionWageWorker {
private:
  std::string fullName;
  Gender gender;
  int salary;
  int percentage;
  int goodsSoldSum;

public:
  CommissionWageWorker() {}

  CommissionWageWorker(std::string, Gender, int, int);

  std::string getFullName() const;

  Gender getGender() const;

  int getSalary() const;

  int getPercentage() const;

  void sell(int);

  int calcWage();
};

CommissionWageWorker enterCommissionWageWorker();

std::ostream &operator<<(std::ostream &, const CommissionWageWorker &);
