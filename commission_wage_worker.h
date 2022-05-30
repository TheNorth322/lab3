#pragma once

#include "common.h"
#include "worker.h"
#include <iostream>
#include <stdexcept>
#include <string>

class CommissionWageWorker : public Worker {
public:
  CommissionWageWorker(std::string, Gender, int, int);

  int getSalary() const;

  int getPercentage() const;

  void work(int);

  int calculateWage();

private:
  int salary;
  int percentage;
  int goodsSoldSum;
};

CommissionWageWorker enterCommissionWageWorker();

std::ostream &operator<<(std::ostream &, const CommissionWageWorker &);
