#pragma once

#include "common.h"
#include "worker.h"
#include <iostream>
#include <stdexcept>
#include <string>

class HourlyWageWorker : public Worker {
public:
  HourlyWageWorker(std::string, Gender, int, int, int);

  int getNormalHourlyWage() const;

  int getOvertimeHourlyWage() const;

  int getStandardOfWorkingHours() const;

  void work(int) override;

  int calculateWage() override;

private:
  int hoursWorked;
  int standardOfWorkingHours;

  int normalHourlyWage;
  int overtimeHourlyWage;

  int workedDays;
};

HourlyWageWorker enterHourlyWageWorker();

std::ostream &operator<<(std::ostream &, const HourlyWageWorker &);
