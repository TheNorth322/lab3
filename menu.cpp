#include "menu.h"

Menu::Menu() : company(Company()) {}

bool Menu::handleError() const {
  if (!std::cin.fail())
    return false;

  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  return true;
}

bool Menu::handleError(const std::string msg) const {
  if (!std::cin.fail())
    return false;

  std::cerr << msg;
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  return true;
}

void Menu::handleAddHourlyWageWorker() {
  HourlyWageWorker worker;
  std::cin >> worker;

  if (handleError())
    return;

  try {
    company.recruitHourlyWageWorker(worker);
    std::cout << "Worker has been successfully recruited!\n";
  } catch (const std::exception &e) {
    std::cerr << "Error! " << e.what() << "\n";
  }
}

void Menu::handleAddCommissionWageWorker() {
  CommissionWageWorker worker;
  std::cin >> worker;

  if (handleError())
    return;

  try {
    company.recruitCommissionWageWorker(worker);
    std::cout << "Worker has been successfully recruited!\n";
  } catch (const std::exception &e) {
    std::cerr << "Error! " << e.what() << "\n";
  }
}

void Menu::handleFireWorkerByFullName() {
  std::string fullName;

  std::cout << "Enter the full name of worker to fire: ";
  std::cin.get();
  std::getline(std::cin, fullName);

  Recruation status = company.getRecruationStatus(fullName);

  // Сотрудник не найден
  if (status == Recruation::None) {
    std::cerr << "Error! Worker wasn't found\n";
    return;
  }

  // Сотрудник найден в обоих группах
  if (status == Recruation::Both) {
    std::cout << "Worker has been found in both groups.\n"
              << "Fire from(1 - Hourly, 2 - Commission, 3 - Both): ";

    std::cin >> status;

    if (handleError("Error! Invalid value. Expected '1' or '2' or '3'"))
      return;
  }

  company.dismissWorkerByFullname(fullName, status);
  std::cout << "Worker has been successfully fired!\n";
}

void Menu::handleSimulateWork() {
  int days;

  std::cout << "Enter number of working days: ";
  std::cin >> days;

  if (handleError("Error! Invalid value. Expected unsigned integer\n"))
    return;
  
  std::cout << "Expenses: " << company.simulateWork(days) << "\n";
  std::cout << "Worked days count: " << company.getWorkedDaysCount() << "\n";
}

void Menu::handlePrintHourlyWageWorkers() const {
  std::cout << "Hourly wage workers: " << company.getHourlyWageWorkers();
}

void Menu::handlePrintCommissionWageWorkers() const {
  std::cout << "Commission wage workers: "
            << company.getCommissionWageWorkers();
}

void Menu::listen() {
  
  // Тестовые данные
  company.recruitHourlyWageWorker(HourlyWageWorker("Petr Petrov", Gender::Male, 500, 700, 10));
  company.recruitHourlyWageWorker(HourlyWageWorker("Ivan Ivanov", Gender::Male, 700, 1000, 15));
  company.recruitHourlyWageWorker(HourlyWageWorker("Ekaterina Pavlovna", Gender::Female, 650, 850, 11));
  
  company.recruitCommissionWageWorker(CommissionWageWorker("Dmitry Dmitrievich", Gender::Male, 800, 5));
  company.recruitCommissionWageWorker(CommissionWageWorker("Nataliya Adreevna", Gender::Female, 700, 8));
  company.recruitCommissionWageWorker(CommissionWageWorker("Aleksandr Aleksandrovich", Gender::Male, 1000, 15));

  while (true) {
    std::cout << "\n\tMenu options\n"
              << ADD_HOURLY_WAGE_WORKER_OPTION << "-Add hourly wage worker\n"
              << ADD_COMMISSION_WAGE_WORKER_OPTION
              << "-Add commission wage worker\n"
              << FIRE_WORKER_BY_FULLNAME_OPTION << "-Fire worker by full name\n"
              << SIMULATE_WORK_OPTION << "-Simulate work\n"
              << PRINT_HOURLY_WAGE_WORKERS_OPTION
              << "-Print hourly wage workers\n"
              << PRINT_COMMISSION_WAGE_WORKERS_OPTION
              << "-Print commission wage workers\n"
              << EXIT_OPTION << "-EXIT\n"
              << "\n";

    std::cout << "Enter option: ";

    std::size_t option;
    std::cin >> option;

    if (handleError("Error! Invalid value. Expected unsigned integer\n")) {
      continue;
    }

    if (option == ADD_HOURLY_WAGE_WORKER_OPTION) {
      handleAddHourlyWageWorker();
      continue;
    }

    if (option == ADD_COMMISSION_WAGE_WORKER_OPTION) {
      handleAddCommissionWageWorker();
      continue;
    }

    if (option == FIRE_WORKER_BY_FULLNAME_OPTION) {
      handleFireWorkerByFullName();
      continue;
    }

    if (option == SIMULATE_WORK_OPTION) {
      handleSimulateWork();
      continue;
    }

    if (option == PRINT_HOURLY_WAGE_WORKERS_OPTION) {
      handlePrintHourlyWageWorkers();
      continue;
    }

    if (option == PRINT_COMMISSION_WAGE_WORKERS_OPTION) {
      handlePrintCommissionWageWorkers();
      continue;
    }

    if (option == EXIT_OPTION) {
      return;
    }

    std::cerr << "Error! Undefined menu option\n";
  }
}
