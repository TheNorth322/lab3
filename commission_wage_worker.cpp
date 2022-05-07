#include "commission_wage_worker.h"
#include <iostream>

CommissionWageWorker::CommissionWageWorker(std::string _fullName,
                                           Gender _gender, int _salary,
                                           int _percentage)
    : fullName(_fullName), gender(_gender), salary(_salary),
      percentage(_percentage) {
  goodsSoldSum = 0;

  if (fullName.length() == 0) {
    throw std::invalid_argument(
        "Invalid 'fullName' argument. The length must be non-zero.");
  }

  if (salary <= 0) {
    throw std::invalid_argument("Invalid 'salary' argument. "
                                "Value must be greater than zero.");
  }

  if (percentage <= 0) {
    throw std::invalid_argument(
        "Invalid 'percentage' argument. "
        "Value must be greater than zero and less than 100.");
  }
}

CommissionWageWorker enterCommissionWageWorker() {
    while (1) 
    {
        Gender gender;
        std::string fullName;
        int salary, percentage, goodsSoldSum;
        
        std::cout << "Enter fullname: ";
        std::cin >> fullName;

        std::cout << "Enter gender(1 - Male, 2 - Female): ";
        std::cin >> gender;

        std::cout << "Enter salary: ";
        std::cin >> salary;

        std::cout << "Enter percentage: ";
        std::cin >> percentage;

        try
        {
          CommissionWageWorker worker(fullName, gender, salary, percentage);
          return worker;
        }
        catch(const std::exception& e)
        {
          std::cerr << e.what() << '\n';
        }
    }
}

std::string CommissionWageWorker::getFullName() const { return fullName; }

Gender CommissionWageWorker::getGender() const { return gender; }

int CommissionWageWorker::getSalary() const { return salary; }

int CommissionWageWorker::getPercentage() const { return percentage; }

void CommissionWageWorker::sell(const int goodsSold) { goodsSoldSum += goodsSold; }

int CommissionWageWorker::calcWage() {
  int addition = (int)((float)goodsSoldSum * (float)(percentage) / 100.);
  int wage = salary + addition;

  goodsSoldSum = 0;

  return wage;
}
