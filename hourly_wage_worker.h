#pragma once

#include "main.h"
#include <stdexcept>
#include <string>

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

  HourlyWageWorker(std::string _fullName, Gender _gender,
                   int _standardOfWorkingHours, int _normalHourlyWage,
                   int _overtimeHourlyWage);
  
  std::string getFullName() const;

  Gender getGender() const;

  int getNormalHourlyWage() const;

  int getOvertimeHourlyWage() const;

  int getStandardOfWorkingHours() const;

  void work(int);

  int calcWage();
};

HourlyWageWorker& enterHourlyWageWorker();
