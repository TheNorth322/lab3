#pragma once
#include <stdexcept>
#include <string>
#include <iostream>
#include "common.h"

class HourlyWageWorker {
private:
  std::string fullName;
  Gender gender;

  int hoursWorked;
  int standardOfWorkingHours;

  int normalHourlyWage;
  int overtimeHourlyWage;

public:

  HourlyWageWorker();

  HourlyWageWorker(std::string, Gender,
                   int, int,
                   int);
  
  std::string getFullName() const;

  Gender getGender() const;

  int getNormalHourlyWage() const;

  int getOvertimeHourlyWage() const;

  int getStandardOfWorkingHours() const;

  void work(int);

  int calcWage();
};

HourlyWageWorker& enterHourlyWageWorker();