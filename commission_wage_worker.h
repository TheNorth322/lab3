#pragma once
#include <stdexcept>
#include <string>
#include <iostream>
#include "common.h"

class CommissionWageWorker {
private:
  std::string fullName;
  Gender gender;
  int salary;
  int percentage;
  int goodsSoldSum;

public:
  CommissionWageWorker();

  CommissionWageWorker(std::string, Gender, int,
                       int );

  std::string getFullName() const;

  Gender getGender() const;
 
  int getSalary() const;

  int getPercentage() const;

  void sell(const int);

  int calcWage();
};

CommissionWageWorker enterCommissionWageWorker();