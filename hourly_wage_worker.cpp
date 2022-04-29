#include "hourly_wage_worker.h"

HourlyWageWorker::HourlyWageWorker(std::string _fullName, Gender _gender,
                                   int _standardOfWorkingHours,
                                   int _normalHourlyWage,
                                   int _overtimeHourlyWage)
    : fullName(_fullName), gender(_gender),
      standardOfWorkingHours(_standardOfWorkingHours),
      normalHourlyWage(_normalHourlyWage),
      overtimeHourlyWage(_overtimeHourlyWage) {
  hoursWorked = 0;

  if (fullName.length() == 0) {
    throw std::invalid_argument(
        "Invalid 'fullName' argument. The length must be non-zero.");
  }

  if (standardOfWorkingHours <= 0) {
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

void HourlyWageWorker::setFullName(const std::string fn) { fullName = fn; }

std::string HourlyWageWorker::getFullName() { return fullName; }

void HourlyWageWorker::setGender(const Gender g) { gender = g; }

void HourlyWageWorker::setNormalHourlyWage(const int hw) { normalHourlyWage = hw; }

void HourlyWageWorker::setOvertimeHourlyWage(const int ohw) { overtimeHourlyWage = ohw; }

void HourlyWageWorker::setStandardOfWorkingHours(const int swh) { standardOfWorkingHours = swh; }

void HourlyWageWorker::work(int hours) { hoursWorked += hours; }

int HourlyWageWorker::calcWage() {
  int normalHoursWorked = hoursWorked < standardOfWorkingHours
                              ? hoursWorked
                              : standardOfWorkingHours;
  int overtimeHoursWorked = hoursWorked - normalHoursWorked;

  hoursWorked = 0;

  return normalHoursWorked * normalHourlyWage +
         overtimeHoursWorked * overtimeHourlyWage;
}
