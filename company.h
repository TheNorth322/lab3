#pragma once

#include "commission_wage_worker.h"
#include "hourly_wage_worker.h"
#include "vec.h"
#include <cstring>
#include <stdexcept>
#include <string>

enum class Recruation { Commission = 1, Hourly, Both, None };

inline std::istream &operator>>(std::istream &stream, Recruation &recruation) {
  int buffer;
  stream >> buffer;

  if (buffer == 1) {
    recruation = Recruation::Hourly;
  } else if (buffer == 2) {
    recruation = Recruation::Commission;
  } else if (buffer == 3) {
    recruation = Recruation::Both;
  }

  return stream;
}

class Company {
private:
  Vector<CommissionWageWorker> commissionWageWorkers;
  Vector<HourlyWageWorker> hourlyWageWorkers;

  const std::size_t maxPrice = 3000;
  const std::size_t minPrice = 1000;
  const std::size_t workingCycle = 15;
  const std::size_t workingDay = 8;
  std::size_t workedDaysCount;

  void dismissHourlyWageWorker(std::string);
  void dismissCommissionWageWorker(std::string);

public:
  Company();

  ~Company();

  void recruitHourlyWageWorker(HourlyWageWorker &);

  void recruitCommissionWageWorker(CommissionWageWorker &);

  Recruation getRecruationStatus(std::string) const;

  const Vector<HourlyWageWorker> &getHourlyWageWorkers() const;

  const Vector<CommissionWageWorker> &getCommissionWageWorkers() const;

  void dismissWorkerByFullname(std::string, Recruation);

  std::size_t simulateWork(int);
};

inline Company::~Company() {
  delete &commissionWageWorkers;
  delete &hourlyWageWorkers;
}
