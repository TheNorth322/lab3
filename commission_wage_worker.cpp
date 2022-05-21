#include "commission_wage_worker.h"

CommissionWageWorker::CommissionWageWorker(std::string _fullName,
                                           Gender _gender, int _salary,
                                           int _percentage)
    : fullName(_fullName), gender(_gender), salary(_salary),
      percentage(_percentage) {
  goodsSoldSum = 0;

  if (fullName.length() == 0) {
    throw std::invalid_argument(
        "Invalid 'fullName' argument. The length must be non-zero");
  }

  if (salary <= 0) {
    throw std::invalid_argument("Invalid 'salary' argument. "
                                "Value must be greater than zero");
  }

  if (percentage <= 0) {
    throw std::invalid_argument(
        "Invalid 'percentage' argument. "
        "Value must be greater than zero and less than 100");
  }
}

std::string CommissionWageWorker::getFullName() const { return fullName; }

Gender CommissionWageWorker::getGender() const { return gender; }

int CommissionWageWorker::getSalary() const { return salary; }

int CommissionWageWorker::getPercentage() const { return percentage; }

void CommissionWageWorker::sell(const int goodsSold) {
  goodsSoldSum += goodsSold;
}

int CommissionWageWorker::calcWage() {
  int addition = (int)((float)goodsSoldSum * (float)(percentage) / 100.);
  int wage = 0;
  if (addition != 0) wage = salary + addition;

  goodsSoldSum = 0;

  return wage;
}

std::istream &operator>>(std::istream &stream, CommissionWageWorker &worker) {
  Gender gender;
  std::string fullName;
  int salary, percentage, goodsSoldSum;

  std::cout << "Enter fullname: ";
  
  stream.get();
  std::getline(stream, fullName);

  std::cout << "Enter gender(1 - Male, 2 - Female): ";
  stream >> gender;

  if (stream.fail()) {
    std::cerr << "Error! Invalid value. Expected '1' or '2'\n";
    return stream;
  }

  std::cout << "Enter salary: ";
  stream >> salary;

  if (stream.fail()) {
    std::cerr << "Error! Invalid value. Expected integer\n";
    return stream;
  }

  std::cout << "Enter percentage: ";
  stream >> percentage;

  if (stream.fail()) {
    std::cerr << "Error! Invalid value. Expected integer\n";
    return stream;
  }

  try {
    worker = CommissionWageWorker(fullName, gender, salary, percentage);
  } catch (const std::exception &e) {
    std::cerr << "Error! " << e.what() << "\n";
    stream.setstate(std::iostream::failbit);
  }

  return stream;
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
