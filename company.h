#pragma once

#include "commission_wage_worker.h"
#include "hourly_wage_worker.h"
#include "main.h"
#include <stdexcept>
#include <string>
#include <cstring>

class Company {
private:
  CommissionWageWorker *commissionWageWorkers;
  std::size_t commissionWageWorkersCount;

  HourlyWageWorker *hourlyWageWorkers;
  std::size_t hourlyWageWorkersCount;

  std::size_t workedDaysCount;
  
  int expenses;

  void dismissHourlyWageWorker(std::size_t pos);
  void dismissCommissionWageWorker(std::size_t pos);

  bool isAlreadyRecruited(std::string fullName);

public:
  Company();

  void recruitHourlyWageWorker(HourlyWageWorker& newWorker);

  void recruitCommissionWageWorker(CommissionWageWorker& newWorker);

  void dismissWorkerByFullname(std::string fullName);

  void simulateWork(int);

  std::size_t getHourlyWageWorkersCount();

  std::size_t getCommissionWageWorkersCount();

  void giveSalary();
};
