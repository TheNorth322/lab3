#pragma once

#include "commission_wage_worker.h"
#include "hourly_wage_worker.h"
#include "vec.h"
#include <cstring>
#include <stdexcept>

class Company {
private:
  Vector<CommissionWageWorker> commissionWageWorkers;
  Vector<HourlyWageWorker> hourlyWageWorkers;

  const std::size_t MAX_PRICE = 3000;
  const std::size_t MIN_PRICE = 1000;
  const std::size_t WORKING_CYCLE = 15;
  const std::size_t WORKING_DAY = 8;

  std::size_t workedDaysCount;

  void dismissHourlyWageWorker(std::string);
  void dismissCommissionWageWorker(std::string);

public:
  Company();

  ~Company() {
    delete &commissionWageWorkers;
    delete &hourlyWageWorkers;
  }

  void recruitHourlyWageWorker(HourlyWageWorker);

  void recruitCommissionWageWorker(CommissionWageWorker);

  Recruation getRecruationStatus(std::string) const;

  const Vector<HourlyWageWorker> &getHourlyWageWorkers() const;

  const Vector<CommissionWageWorker> &getCommissionWageWorkers() const;

  void dismissWorkerByFullname(std::string, Recruation);

  std::size_t simulateWork(int);
};
