#include "hourly_wage_worker.h"

HourlyWageWorker::HourlyWageWorker(std::string _fullName, Gender _gender,
                                   int _normalHourlyWage,
                                   int _overtimeHourlyWage,
                                   int _standardOfWorkingHours)
    : fullName(_fullName), gender(_gender),
      standardOfWorkingHours(_standardOfWorkingHours),
      normalHourlyWage(_normalHourlyWage),
      overtimeHourlyWage(_overtimeHourlyWage) {
  hoursWorked = 0;
  workedDays = 0;

  if (fullName.length() == 0) {
    throw std::invalid_argument(
        "Invalid 'fullName' argument. The length must be non-zero");
  }

  if (standardOfWorkingHours <= 0) {
    throw std::invalid_argument("Invalid 'standardOfWorkingHours' argument. "
                                "Value must be greater than zero");
  }

  if (normalHourlyWage <= 0) {
    throw std::invalid_argument("Invalid 'normalHourlyWage' argument. "
                                "Value must be greater than zero");
  }

  if (overtimeHourlyWage <= 0) {
    throw std::invalid_argument("Invalid 'overtimeHourlyWage' argument. "
                                "Value must be greater than zero");
  }
}

std::string HourlyWageWorker::getFullName() const { return fullName; }

Gender HourlyWageWorker::getGender() const { return gender; }

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

int HourlyWageWorker::calcWage() {
  int normalHoursWorked = hoursWorked < standardOfWorkingHours * workedDays
                              ? hoursWorked
                              : standardOfWorkingHours * workedDays;
  int overtimeHoursWorked = hoursWorked - normalHoursWorked;

  hoursWorked = 0;
  workedDays = 0;

  return normalHoursWorked * normalHourlyWage +
         overtimeHoursWorked * overtimeHourlyWage;
}

std::istream &operator>>(std::istream &stream, HourlyWageWorker &worker) {
  Gender gender;
  std::string fullName;
  int normalHourlyWage, overtimeHourlyWage, standardOfWorkingHours;

  std::cout << "Enter fullname: ";

  stream.get();
  std::getline(stream, fullName);

  std::cout << "Enter gender(1 - Male, 2 - Female): ";
  stream >> gender;

  if (stream.fail()) {
    std::cerr << "Error! Invalid value. Expected '1' or '2'\n";
    return stream;
  }

  std::cout << "Enter normal hourly wage: ";
  stream >> normalHourlyWage;

  if (stream.fail()) {
    std::cerr << "Error! Invalid value. Expected integer\n";
    return stream;
  }

  std::cout << "Enter overtime wage: ";
  stream >> overtimeHourlyWage;

  if (stream.fail()) {
    std::cerr << "Error! Invalid value. Expected integer\n";
    return stream;
  }

  std::cout << "Enter standard of working hours: ";
  stream >> standardOfWorkingHours;

  if (stream.fail()) {
    std::cerr << "Error! Invalid value. Expected integer\n";
    return stream;
  }

  try {
    worker = HourlyWageWorker(fullName, gender, standardOfWorkingHours,
                              normalHourlyWage, overtimeHourlyWage);
  } catch (const std::exception &e) {
    std::cerr << "Error! " << e.what() << "\n";
    stream.setstate(std::iostream::failbit);
  }

  return stream;
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
