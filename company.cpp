#include "company.h"

Company::Company()
    : commissionWageWorkers(Vector<CommissionWageWorker>()),
      hourlyWageWorkers(Vector<HourlyWageWorker>()),
      workedDaysCount(0), expenses(0) {}

void Company::recruitHourlyWageWorker(HourlyWageWorker &newWorker)
{
  for (std::size_t i = 0; i < hourlyWageWorkers.getSize(); i++)
    if (hourlyWageWorkers[i].getFullName() == newWorker.getFullName())
      throw std::invalid_argument("Worker with name '" + newWorker.getFullName() +
                                  "' already recruited.");

  HourlyWageWorker *newWorkers =
      new HourlyWageWorker[hourlyWageWorkers.getSize() + 1];

  std::memcpy(newWorkers, hourlyWageWorkers, hourlyWageWorkers.getSize());
  newWorkers[hourlyWageWorkers.getSize()] = newWorker;

  delete[] hourlyWageWorkers;
  hourlyWageWorkers = newWorkers;

  hourlyWageWorkers.getSize() += 1;
}

void Company::recruitCommissionWageWorker(CommissionWageWorker &newWorker)
{
  for (std::size_t i = 0; i < commissionWageWorkersCount; i++)
    if (commissionWageWorkers[i].getFullName() == newWorker.getFullName())
      throw std::invalid_argument("Worker with name '" + newWorker.getFullName() +
                                  "' already recruited.");

  CommissionWageWorker *newWorkers =
      new CommissionWageWorker[commissionWageWorkersCount + 1];

  std::memcpy(newWorkers, commissionWageWorkers, commissionWageWorkersCount);
  newWorkers[commissionWageWorkersCount] = newWorker;

  delete[] commissionWageWorkers;
  commissionWageWorkers = newWorkers;

  commissionWageWorkersCount += 1;
}

void Company::dismissHourlyWageWorker(std::string fullName)
{
  HourlyWageWorker *newWorkers =
      new HourlyWageWorker[hourlyWageWorkersCount - 1];
  int pos;

  for (int i = 0; i < hourlyWageWorkersCount; i++)
  {
    if (commissionWageWorkers[i].getFullName() == fullName)
    {
      pos = i;
      break;
    }
  }

  std::memcpy(newWorkers, hourlyWageWorkers, pos);
  std::memcpy(newWorkers + pos, hourlyWageWorkers + pos + 1,
              hourlyWageWorkersCount - pos - 1);

  delete[] hourlyWageWorkers;

  hourlyWageWorkers = newWorkers;
  hourlyWageWorkersCount -= 1;
}

void Company::dismissCommissionWageWorker(std::string fullName)
{
  CommissionWageWorker *newWorkers =
      new CommissionWageWorker[commissionWageWorkersCount - 1];
  int pos;

  for (int i = 0; i < commissionWageWorkersCount; i++)
  {
    if (commissionWageWorkers[i].getFullName() == fullName)
    {
      pos = i;
      break;
    }
  }

  std::memcpy(newWorkers, commissionWageWorkers, pos);
  std::memcpy(newWorkers + pos, commissionWageWorkers + pos + 1,
              commissionWageWorkersCount - pos - 1);

  delete[] commissionWageWorkers;

  commissionWageWorkers = newWorkers;
  commissionWageWorkersCount -= 1;
}

Recruation Company::checkRecruation(std::string fullName)
{
  Recruation status = Recruation::None;

  for (std::size_t i = 0; i < hourlyWageWorkersCount; i++)
    if (hourlyWageWorkers[i].getFullName() == fullName)
      status = Recruation::Hourly;

  for (std::size_t i = 0; i < commissionWageWorkersCount; i++)
  {
    if (commissionWageWorkers[i].getFullName() != fullName)
      continue;
    if (status == Recruation::Hourly)
      status = Recruation::Both;
    else
      status = Recruation::Commission;
  }

  return status;
}

void Company::dismissWorkerByFullname(std::string fullName, Recruation status)
{
  if (status == Recruation::Both)
  {
    dismissHourlyWageWorker(fullName);
    dismissCommissionWageWorker(fullName);
  }

  if (status == Recruation::Hourly)
    dismissHourlyWageWorker(fullName);

  if (status == Recruation::Commission)
    dismissCommissionWageWorker(fullName);
}

void Company::simulateWork(int days)
{
  for (workedDaysCount; workedDaysCount < days; workedDaysCount++)
  {
    for (int i = 0; i < hourlyWageWorkersCount; i++)
    {
      if (workedDaysCount % workingCycle == 0) expenses += hourlyWageWorkers[i].calcWage();
      hourlyWageWorkers[i].work(std::rand() % workingDay); 
    }
    for (int i = 0; i < commissionWageWorkersCount; i++)
    {
      if (workedDaysCount % workingCycle == 0) expenses += commissionWageWorkers[i].calcWage();
      commissionWageWorkers[i].sell(std::rand() % (maxPrice - minPrice) + minPrice); 
    }
  }
}
