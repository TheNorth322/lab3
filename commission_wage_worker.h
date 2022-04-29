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

  void setFullName(const std::string);

  std::string getFullName();

  void setGender(const Gender);
 
  void setSalary(const int);

  void setPercentage(const int);

  void sell(const int);

  int calcWage();
};
