#pragma once

#include "main.h"
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
  CommissionWageWorker();

  CommissionWageWorker(std::string _fullName, Gender _gender, int _salary,
                       int _percentage);

  std::string getFullName() const;

  Gender getGender() const;
 
  int getSalary() const;

  int getPercentage() const;

  void sell(const int);

  int calcWage();
};

CommissionWageWorker enterCommissionWageWorker();