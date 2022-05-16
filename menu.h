#pragma once

#include "company.h"
#include "cstring"
#include "vec.h"
#include <limits>

class Menu {
public:
  Menu();

  void listen();

private:
  Company company;

  const std::size_t ADD_HOURLY_WAGE_WORKER_OPTION = 1;
  const std::size_t ADD_COMMISSION_WAGE_WORKER_OPTION = 2;
  const std::size_t FIRE_WORKER_BY_FULLNAME_OPTION = 3;
  const std::size_t SIMULATE_WORK_OPTION = 4;
  const std::size_t PRINT_HOURLY_WAGE_WORKERS_OPTION = 5;
  const std::size_t PRINT_COMMISSION_WAGE_WORKERS_OPTION = 6;
  const std::size_t EXIT_OPTION = 7;

  bool handleError() const;
  bool handleError(std::string) const;

  void handleAddHourlyWageWorker();

  void handleAddCommissionWageWorker();

  void handleFireWorkerByFullName();

  void handleSimulateWork();

  void handlePrintHourlyWageWorkers() const;

  void handlePrintCommissionWageWorkers() const;
};
