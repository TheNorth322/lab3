#pragma once

#include "commission_wage_worker.h"
#include "hourly_wage_worker.h"
#include <cstring>
#include <ctime>
#include <stdexcept>
#include <vector>

class Company {
public:
  Company();

  void recruitHourlyWageWorker(HourlyWageWorker);

  void recruitCommissionWageWorker(CommissionWageWorker);

  Recruation getRecruationStatus(const std::string&) const;

  std::size_t getWorkedDaysCount() const;

  const std::vector<HourlyWageWorker> &getHourlyWageWorkers() const;

  const std::vector<CommissionWageWorker> &getCommissionWageWorkers() const;

  void dismissWorkerByFullname(const std::string&, Recruation);

  std::size_t simulateWork(int);

private:
  std::vector<CommissionWageWorker> commissionWageWorkers;
  std::vector<HourlyWageWorker> hourlyWageWorkers;

  const std::size_t MAX_PRICE = 15000;
  const std::size_t WORKING_CYCLE = 15;

  std::size_t workedDaysCount;

  void dismissHourlyWageWorker(const std::string&);

  void dismissCommissionWageWorker(const std::string&);
};
