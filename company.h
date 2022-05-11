#pragma once

#include "commission_wage_worker.h"
#include "hourly_wage_worker.h"
#include "main.h"
#include "vector.h"
#include <cstring>
#include <stdexcept>
#include <string>

enum class Recruation { Commission = 1, Hourly, Both, None };

inline std::istream &operator>>(std::istream &stream, Recruation &recruation) {
  stream >> recruation;
  return stream;
}

class Company {
private:
  Vector<CommissionWageWorker> commissionWageWorkers;

  Vector<HourlyWageWorker> hourlyWageWorkers;

  std::size_t workedDaysCount;

  const int maxPrice = 3000;
  const int minPrice = 1000;
  const int workingCycle = 15;
  const int workingDay = 8;
  int expenses;

  void dismissHourlyWageWorker(std::string);
  void dismissCommissionWageWorker(std::string);

  bool isAlreadyRecruited(std::string fullName) const;

public:
  Company();

  ~Company();

  void recruitHourlyWageWorker(HourlyWageWorker &);

  void recruitCommissionWageWorker(CommissionWageWorker &);

  Recruation getRecruationStatus(std::string) const;

  Vector<HourlyWageWorker> getHourlyWageWorkers() const;

  Vector<CommissionWageWorker> getCommissionWageWorkers() const;

  void dismissWorkerByFullname(std::string, Recruation);

  void simulateWork(int);
};

inline Company::~Company() {
  delete &commissionWageWorkers;
  delete &hourlyWageWorkers;
}
