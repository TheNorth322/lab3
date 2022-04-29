#include "company.h"

Company::Company()
    : commissionWageWorkers(new CommissionWageWorker[0]),
      commissionWageWorkersCount(0), hourlyWageWorkers(new HourlyWageWorker[0]),
      hourlyWageWorkersCount(0), workedDaysCount(0) {}

bool Company::isAlreadyRecruited(std::string fullName) {
  for (std::size_t i = 0; i < hourlyWageWorkersCount; i++) {
    if (hourlyWageWorkers[i].getFullName() == fullName) {
      return true;
    }
  }

  for (std::size_t i = 0; i < commissionWageWorkersCount; i++) {
    if (commissionWageWorkers[i].getFullName() == fullName) {
      dismissCommissionWageWorker(i);
      return true;
    }
  }

  return false;
}

void Company::recruitHourlyWageWorker(HourlyWageWorker& newWorker) {
  if (isAlreadyRecruited(newWorker.getFullName())) {
    throw std::invalid_argument("Worker with name '" + newWorker.getFullName() +
                                "' already recruited.");
  }

  HourlyWageWorker *newWorkers =
      new HourlyWageWorker[hourlyWageWorkersCount + 1];

  std::memcpy(newWorkers, hourlyWageWorkers, hourlyWageWorkersCount);
  newWorkers[hourlyWageWorkersCount] = newWorker;

  delete[] hourlyWageWorkers;
  hourlyWageWorkers = newWorkers;

  hourlyWageWorkersCount += 1;
}

void Company::recruitCommissionWageWorker(CommissionWageWorker& newWorker) {
  if (isAlreadyRecruited(newWorker.getFullName())) {
    throw std::invalid_argument("Worker with name '" + newWorker.getFullName() +
                                "' already recruited.");
  }

  CommissionWageWorker *newWorkers =
      new CommissionWageWorker[commissionWageWorkersCount + 1];

  std::memcpy(newWorkers, commissionWageWorkers, commissionWageWorkersCount);
  newWorkers[commissionWageWorkersCount] = newWorker;

  delete[] commissionWageWorkers;
  commissionWageWorkers = newWorkers;

  commissionWageWorkersCount += 1;
}

void Company::dismissHourlyWageWorker(std::size_t pos) {
  HourlyWageWorker *newWorkers =
      new HourlyWageWorker[hourlyWageWorkersCount - 1];

  std::memcpy(newWorkers, hourlyWageWorkers, pos);
  std::memcpy(newWorkers + pos, hourlyWageWorkers + pos + 1,
              hourlyWageWorkersCount - pos - 1);

  delete[] hourlyWageWorkers;

  hourlyWageWorkers = newWorkers;
  hourlyWageWorkersCount -= 1;
}

void Company::dismissCommissionWageWorker(std::size_t pos) {
  CommissionWageWorker *newWorkers =
      new CommissionWageWorker[commissionWageWorkersCount - 1];

  std::memcpy(newWorkers, commissionWageWorkers, pos);
  std::memcpy(newWorkers + pos, commissionWageWorkers + pos + 1,
              commissionWageWorkersCount - pos - 1);

  delete[] commissionWageWorkers;

  commissionWageWorkers = newWorkers;
  commissionWageWorkersCount -= 1;
}

void Company::dismissWorkerByFullname(std::string fullName) {

  for (std::size_t i = 0; i < hourlyWageWorkersCount; i++) {
    if (hourlyWageWorkers[i].getFullName() == fullName) {
      dismissHourlyWageWorker(i);
      return;
    }
  }

  for (std::size_t i = 0; i < commissionWageWorkersCount; i++) {
    if (commissionWageWorkers[i].getFullName() == fullName) {
      dismissCommissionWageWorker(i);
      return;
    }
  }
}

void Company::simulateWork(int days) {
    for (int j = 0; j < days; j++) {
        workedDaysCount++;
        for (int i = 0; i < hourlyWageWorkersCount; i++) {
            hourlyWageWorkers[i].work(rand() % 20); // генерируем кол-во отработанных часов за день | заменить генераторы
            expenses += hourlyWageWorkers[i].calcWage();
        }
        for (int i = 0; i < commissionWageWorkersCount; i++) {
            commissionWageWorkers[i].sell(rand() % 1000 + 9000); // генерируем стоимость проданных товаров | заменить генераторы
            expenses += commissionWageWorkers[i].calcWage();
        }
    }
}

std::size_t getHourlyWageWorkersCount() { return hourlyWageWorkersCount };
