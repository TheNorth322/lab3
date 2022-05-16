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
  CommissionWageWorker()
      : fullName(""), gender(Gender::Male), salary(0), percentage(0),
        goodsSoldSum(0) {}

  CommissionWageWorker(std::string, Gender, int, int);

  std::string getFullName() const;

  Gender getGender() const;

  int getSalary() const;

  int getPercentage() const;

  void sell(int);

  int calcWage();
};

std::istream &operator>>(std::istream &, CommissionWageWorker &);
std::ostream &operator<<(std::ostream &, const CommissionWageWorker &);
