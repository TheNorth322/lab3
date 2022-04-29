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
  static HourlyWageWorker& enterFromConsole();

  HourlyWageWorker();

  HourlyWageWorker(std::string _fullName, Gender _gender,
                   int _standardOfWorkingHours, int _normalHourlyWage,
                   int _overtimeHourlyWage);

  void setFullName(const std::string);
  
  std::string getFullName();

  void setGender(const Gender);

  void setNormalHourlyWage(const int);

  void setOvertimeHourlyWage(const int);

  void setStandardOfWorkingHours(const int);

  void work(int);

  int calcWage();
};
