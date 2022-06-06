#include "company.h"

Company::Company()
    : commissionWageWorkers(std::vector<CommissionWageWorker>()),
      hourlyWageWorkers(std::vector<HourlyWageWorker>()), workedDaysCount(0) {}

//Найм сотрудника с почасовой оплатой
void Company::recruitHourlyWageWorker(HourlyWageWorker newWorker) {
  for (std::size_t i = 0; i < hourlyWageWorkers.size(); i++)
    if (hourlyWageWorkers[i].getFullName() == newWorker.getFullName())
      throw std::invalid_argument("Worker with name '" +
                                  newWorker.getFullName() +
                                  "' already recruited");

  hourlyWageWorkers.push_back(newWorker);
}

//Найм сотрудника с коммиссионной оплатой
void Company::recruitCommissionWageWorker(CommissionWageWorker newWorker) {
  for (std::size_t i = 0; i < commissionWageWorkers.size(); i++)
    if (commissionWageWorkers[i].getFullName() == newWorker.getFullName())
      throw std::invalid_argument("Worker with name '" +
                                  newWorker.getFullName() +
                                  "' already recruited");

  commissionWageWorkers.push_back(newWorker);
}

//Увольнение сотрудника с почасовой оплатой
void Company::dismissHourlyWageWorker(const std::string &fullName) {
  for (std::size_t i = 0; i < hourlyWageWorkers.size(); i++)
    if (fullName == hourlyWageWorkers[i].getFullName())
      hourlyWageWorkers.erase(std::next(hourlyWageWorkers.begin(), i));
}

// Увольнение сотрудника с коммиссионной оплатой
void Company::dismissCommissionWageWorker(const std::string &fullName) {
  for (std::size_t i = 0; i < commissionWageWorkers.size(); i++)
    if (commissionWageWorkers[i].getFullName() == fullName)
      commissionWageWorkers.erase(std::next(commissionWageWorkers.begin(), i));
}

// Получение статуса найма сотрудника
Recruation Company::getRecruationStatus(const std::string &fullName) const {
  Recruation status = Recruation::None;

  for (std::size_t i = 0; i < hourlyWageWorkers.size(); i++)
    if (hourlyWageWorkers[i].getFullName() == fullName)
      status = Recruation::Hourly;

  for (std::size_t i = 0; i < commissionWageWorkers.size(); i++) {
    if (commissionWageWorkers[i].getFullName() != fullName)
      continue;

    if (status == Recruation::Hourly)
      status = Recruation::Both;
    else
      status = Recruation::Commission;
  }

  return status;
}
std::size_t Company::getWorkedDaysCount() const { return workedDaysCount; }

const std::vector<HourlyWageWorker> &Company::getHourlyWageWorkers() const {
  return hourlyWageWorkers;
}

const std::vector<CommissionWageWorker> &
Company::getCommissionWageWorkers() const {
  return commissionWageWorkers;
}

// Увольнение сотрудника по ФИО
void Company::dismissWorkerByFullname(const std::string &fullName,
                                      Recruation status) {
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
  std::srand(std::time(nullptr));
  std::size_t expenses = 0;

  for (std::size_t workedDays = 0; workedDays < days; workedDays++) {
    for (std::size_t i = 0; i < hourlyWageWorkers.size(); i++) {
      HourlyWageWorker &worker = hourlyWageWorkers[i];

      std::size_t min_working_hours = worker.getStandardOfWorkingHours();
      std::size_t max_working_hours =
          min_working_hours + (24 - min_working_hours) / 2;

      worker.work(std::rand() % max_working_hours);
    }

    for (std::size_t i = 0; i < commissionWageWorkers.size(); i++) {
      commissionWageWorkers[i].work(std::rand() % MAX_PRICE);
    }

    workedDaysCount++;

    if (workedDaysCount % WORKING_CYCLE == 0) {
      for (std::size_t i = 0; i < hourlyWageWorkers.size(); i++)
        expenses += hourlyWageWorkers[i].calculateWage();
      for (std::size_t i = 0; i < commissionWageWorkers.size(); i++)
        expenses += commissionWageWorkers[i].calculateWage();
    }
  }

  workedDaysCount %= 15;

  return expenses;
}
