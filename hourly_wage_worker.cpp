#include "hourly_wage_worker.h"

HourlyWageWorker::HourlyWageWorker(std::string _fullName, Gender _gender,
                                   int _normalHourlyWage,
                                   int _overtimeHourlyWage,
                                   int _standardOfWorkingHours)
    : Worker(_fullName, _gender),
      standardOfWorkingHours(_standardOfWorkingHours),
      normalHourlyWage(_normalHourlyWage),
      overtimeHourlyWage(_overtimeHourlyWage), hoursWorked(0), workedDays(0) {

  if (standardOfWorkingHours <= 0 && standardOfWorkingHours > 24) {
    throw std::invalid_argument("Invalid 'standardOfWorkingHours' argument. "
                                "Value must be greater than zero.");
  }

  if (normalHourlyWage <= 0) {
    throw std::invalid_argument("Invalid 'normalHourlyWage' argument. "
                                "Value must be greater than zero.");
  }

  if (overtimeHourlyWage <= 0) {
    throw std::invalid_argument("Invalid 'overtimeHourlyWage' argument. "
                                "Value must be greater than zero.");
  }
}

int HourlyWageWorker::getNormalHourlyWage() const { return normalHourlyWage; }

int HourlyWageWorker::getOvertimeHourlyWage() const {
  return overtimeHourlyWage;
}

int HourlyWageWorker::getStandardOfWorkingHours() const {
  return standardOfWorkingHours;
}

void HourlyWageWorker::work(int hours) {
  hoursWorked += hours;
  workedDays++;
}

int HourlyWageWorker::calculateWage() {
  int normalHoursWorked = hoursWorked < standardOfWorkingHours * workedDays
                              ? hoursWorked
                              : standardOfWorkingHours * workedDays;
  int overtimeHoursWorked = hoursWorked - normalHoursWorked;

  hoursWorked = 0;
  workedDays = 0;

  return normalHoursWorked * normalHourlyWage +
         overtimeHoursWorked * overtimeHourlyWage;
}

HourlyWageWorker enterHourlyWageWorker() {
  Gender gender;
  std::string fullName;
  int normalHourlyWage, overtimeHourlyWage, standardOfWorkingHours;

  std::cout << "Enter fullname: ";

  std::cin.get();
  std::getline(std::cin, fullName);

  std::cout << "Enter gender(1 - Male, 2 - Female): ";
  std::cin >> gender;

  if (std::cin.fail()) {
    throw std::invalid_argument("Invalid value. Expected '1' or '2'\n");
  }

  std::cout << "Enter normal hourly wage: ";
  std::cin >> normalHourlyWage;

  if (std::cin.fail()) {
    throw std::invalid_argument("Invalid value. Expected integer\n");
  }

  std::cout << "Enter overtime wage: ";
  std::cin >> overtimeHourlyWage;

  if (std::cin.fail()) {
    throw std::invalid_argument("Invalid value. Expected integer\n");
  }

  std::cout << "Enter standard of working hours: ";
  std::cin >> standardOfWorkingHours;

  if (std::cin.fail()) {
    throw std::invalid_argument("Invalid value. Expected integer\n");
  }

  HourlyWageWorker worker =
      HourlyWageWorker(fullName, gender, normalHourlyWage, overtimeHourlyWage,
                       standardOfWorkingHours);
  return worker;
}

std::ostream &operator<<(std::ostream &stream, const HourlyWageWorker &worker) {
  stream << " {"
         << "\n   fullName: " << worker.getFullName()
         << "\n   gender: " << worker.getGender()
         << "\n   normalHourlyWage: " << worker.getNormalHourlyWage()
         << "\n   overtimeHourlyWage: " << worker.getOvertimeHourlyWage()
         << "\n   standardOfWorkingHours: "
         << worker.getStandardOfWorkingHours() << "\n }";

  return stream;
}
