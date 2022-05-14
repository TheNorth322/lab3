#include "main.h"
#include "vec.cpp"

int main() {
  Company *company = new Company();
  menu(*company);
  return 0;
}

void fireWorker(Company &company, std::string fullName) {
  Recruation status = company.getRecruationStatus(fullName);

  if (status == Recruation::None) {
    std::cout << "Worker wasn't found!" << std::endl;
    return;
  }

  if (status == Recruation::Both) {
    std::cout << "Worker has been found in both groups." << std::endl
              << "Fire from? (1 - Hourly, 2 - Commission, 3 - Both): ";

    std::cin >> status;
  }
  company.dismissWorkerByFullname(fullName, status);
}

void menu(Company &company) {
  while (1) {
    std::cout << "\tMenu options\n"
              << "1-Add hourly wage worker\n"
              << "2-Add commission wage worker\n"
              << "3-Fire worker by full name\n"
              << "4-Simulate work\n"
              << "5-Print hourly wage workers\n"
              << "6-Print commission wage workers\n"
              << "7-EXIT\n";

    std::cout << "Enter option: ";

    std::string option;
    std::cin >> option;

    if (option.compare("1") == 0) {
      HourlyWageWorker hworker = enterHourlyWageWorker();
      company.recruitHourlyWageWorker(hworker);

      std::cout << "\nWorker has been successfully recruited!\n";
      continue;
    }

    if (option.compare("2") == 0) {
      CommissionWageWorker cworker = enterCommissionWageWorker();
      company.recruitCommissionWageWorker(cworker);

      std::cout << "\nWorker has been successfully recruited!\n";
      continue;
    }

    if (option.compare("3") == 0) {
      std::string fullName;

      std::cout << "Enter the full name of worker to fire: ";
      std::cin >> fullName;

      fireWorker(company, fullName);
      continue;
    }

    if (option.compare("4") == 0) {
      int days;

      std::cout << "Enter number of working days: ";
      std::cin >> days;
      std::cout << "Expenses: " << company.simulateWork(days) << "\n";

      continue;
    }

    if (option.compare("5") == 0) {
      std::cout << company.getHourlyWageWorkers();
      continue;
    }

    if (option.compare("6") == 0) {
      std::cout << company.getCommissionWageWorkers();
      continue;
    }

    if (option.compare("7") == 0) {
      return;
    }

    std::cout << "Wrong! Undefined munu option";
    std::cout << "\n";
  }
}
