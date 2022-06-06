#include "commission_wage_worker.h"

CommissionWageWorker::CommissionWageWorker(std::string _fullName,
                                           Gender _gender, int _salary,
                                           int _percentage)
    : Worker(_fullName, _gender), salary(_salary), percentage(_percentage),
      goodsSoldSum(0) {

  if (salary <= 0) {
    throw std::invalid_argument("Invalid 'salary' argument. "
                                "Value must be greater than zero");
  }

  if (percentage <= 0 && percentage > 100) {
    throw std::invalid_argument(
        "Invalid 'percentage' argument. "
        "Value must be greater than zero and less than 100");
  }
}

int CommissionWageWorker::getSalary() const { return salary; }

int CommissionWageWorker::getPercentage() const { return percentage; }

void CommissionWageWorker::work(const int goodsSold) {
  goodsSoldSum += goodsSold;
}

int CommissionWageWorker::calculateWage() {
  int addition = (int)((float)goodsSoldSum * (float)(percentage) / 100.);
  int wage = 0;
  if (addition != 0)
    wage = salary + addition;

  goodsSoldSum = 0;

  return wage;
}

CommissionWageWorker enterCommissionWageWorker() {
  Gender gender;
  std::string fullName;
  int salary, percentage;

  std::cout << "Enter fullname: ";

  std::cin.get();
  std::getline(std::cin, fullName);

  std::cout << "Enter gender(1 - Male, 2 - Female): ";
  std::cin >> gender;

  if (std::cin.fail()) {
    throw std::invalid_argument("Invalid value. Expected '1' or '2'\n");
  }

  std::cout << "Enter salary: ";
  std::cin >> salary;

  if (std::cin.fail()) {
    throw std::invalid_argument("Invalid value. Expected integer\n");
  }

  std::cout << "Enter percentage: ";
  std::cin >> percentage;

  if (std::cin.fail()) {
    throw std::invalid_argument("Invalid value. Expected integer\n");
  }

  CommissionWageWorker worker =
      CommissionWageWorker(fullName, gender, salary, percentage);

  return worker;
}

std::ostream &operator<<(std::ostream &stream,
                         const CommissionWageWorker &worker) {
  stream << " {"
         << "\n   fullName: " << worker.getFullName()
         << "\n   gender: " << worker.getGender()
         << "\n   salary: " << worker.getSalary()
         << "\n   percentage: " << worker.getPercentage() << "\n }";

  return stream;
}
