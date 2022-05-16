#include "company.h"

Company::Company()
    : commissionWageWorkers(Vector<CommissionWageWorker>()),
      hourlyWageWorkers(Vector<HourlyWageWorker>()), workedDaysCount(0) {}

//Найм сотрудника с почасовой оплатой
void Company::recruitHourlyWageWorker(HourlyWageWorker newWorker) {
  for (std::size_t i = 0; i < hourlyWageWorkers.getSize(); i++)
    if (hourlyWageWorkers[i].getFullName() == newWorker.getFullName())
      throw std::invalid_argument("Worker with name '" +
                                  newWorker.getFullName() +
                                  "' already recruited.");

  hourlyWageWorkers.push(newWorker);
}

//Найм сотрудника с коммиссионной оплатой
void Company::recruitCommissionWageWorker(CommissionWageWorker newWorker) {
  for (std::size_t i = 0; i < commissionWageWorkers.getSize(); i++)
    if (commissionWageWorkers[i].getFullName() == newWorker.getFullName())
      throw std::invalid_argument("Worker with name '" +
                                  newWorker.getFullName() +
                                  "' already recruited.");

  commissionWageWorkers.push(newWorker);
}

//Увольнение сотрудника с почасовой оплатой
void Company::dismissHourlyWageWorker(std::string fullName) {
  for (int i = 0; i < hourlyWageWorkers.getSize(); i++)
    if (hourlyWageWorkers[i].getFullName() == fullName)
      hourlyWageWorkers.del(i);
}

// Увольнение сотрудника с коммиссионной оплатой
void Company::dismissCommissionWageWorker(std::string fullName) {
  for (int i = 0; i < commissionWageWorkers.getSize(); i++)
    if (commissionWageWorkers[i].getFullName() == fullName)
      commissionWageWorkers.del(i);
}

// Получение статуса найма сотрудника
Recruation Company::getRecruationStatus(std::string fullName) const {
  Recruation status = Recruation::None;

  for (std::size_t i = 0; i < hourlyWageWorkers.getSize(); i++)
    if (hourlyWageWorkers[i].getFullName() == fullName)
      status = Recruation::Hourly;

  for (std::size_t i = 0; i < commissionWageWorkers.getSize(); i++) {
    if (commissionWageWorkers[i].getFullName() != fullName)
      continue;

    if (status == Recruation::Hourly)
      status = Recruation::Both;
    else
      status = Recruation::Commission;
  }

  return status;
}

const Vector<HourlyWageWorker> &Company::getHourlyWageWorkers() const {
  return hourlyWageWorkers;
}

const Vector<CommissionWageWorker> &Company::getCommissionWageWorkers() const {
  return commissionWageWorkers;
}

// Увольнение сотрудника по ФИО
void Company::dismissWorkerByFullname(std::string fullName, Recruation status) {
  if (status == Recruation::Both) {
    dismissHourlyWageWorker(fullName);
    dismissCommissionWageWorker(fullName);
  }

  if (status == Recruation::Hourly)
    dismissHourlyWageWorker(fullName);

  if (status == Recruation::Commission)
    dismissCommissionWageWorker(fullName);
}

// Моделирование работы
std::size_t Company::simulateWork(int days) {
  std::size_t expenses = 0;

  for (; workedDaysCount < days; workedDaysCount++) {
    for (int i = 0; i < hourlyWageWorkers.getSize(); i++) {
      if (workedDaysCount % workingCycle == 0)
        expenses += hourlyWageWorkers[i].calcWage();

      hourlyWageWorkers[i].work(std::rand() % workingDay);
    }

    for (int i = 0; i < commissionWageWorkers.getSize(); i++) {
      if (workedDaysCount % workingCycle == 0)
        expenses += commissionWageWorkers[i].calcWage();

      commissionWageWorkers[i].sell(std::rand() % (maxPrice - minPrice) +
                                    minPrice);
    }
  }

  return expenses;
}
