#pragma once

#include "commission_wage_worker.h"
#include "hourly_wage_worker.h"
#include "vec.h"
#include <cstring>
#include <stdexcept>
#include <ctime>

class Company {
private:
  Vector<CommissionWageWorker> commissionWageWorkers;
  Vector<HourlyWageWorker> hourlyWageWorkers;

  const std::size_t MAX_PRICE = 15000;
  const std::size_t WORKING_CYCLE = 15;

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
  
  std::size_t getWorkedDaysCount() const;

  const Vector<HourlyWageWorker> &getHourlyWageWorkers() const;

  const Vector<CommissionWageWorker> &getCommissionWageWorkers() const;

  void dismissWorkerByFullname(std::string, Recruation);

  std::size_t simulateWork(int);
};
