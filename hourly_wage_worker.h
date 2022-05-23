#pragma once

#include "common.h"
#include <iostream>
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
  
  std::size_t workedDays;

public:
  HourlyWageWorker()
      : fullName(""), gender(Gender::Female), hoursWorked(0),
        standardOfWorkingHours(0), normalHourlyWage(0), overtimeHourlyWage(0), workedDays(0) {}

  HourlyWageWorker(std::string, Gender, int, int, int);

  std::string getFullName() const;

  Gender getGender() const;

  int getNormalHourlyWage() const;

  int getOvertimeHourlyWage() const;

  int getStandardOfWorkingHours() const;

  void work(int);

  int calcWage();
};

std::istream &operator>>(std::istream &, HourlyWageWorker &);
std::ostream &operator<<(std::ostream &, const HourlyWageWorker &);
