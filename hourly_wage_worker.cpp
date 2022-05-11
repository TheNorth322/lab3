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

std::string HourlyWageWorker::getFullName() const { return fullName; }

Gender HourlyWageWorker::getGender() const { return gender; }

int HourlyWageWorker::getNormalHourlyWage() const { return normalHourlyWage; }

int HourlyWageWorker::getOvertimeHourlyWage() const { return overtimeHourlyWage; }

int HourlyWageWorker::getStandardOfWorkingHours() const { return standardOfWorkingHours; }

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

HourlyWageWorker& enterHourlyWageWorker() {
    while (1)
    {
        Gender gender;
        std::string fullName;
        int hourlyWage, overtimeHourlyWage, standardOfWorkingHours;

        std::cout << "Enter fullname: ";
        std::cin >> fullName;

        std::cout << "Enter gender(1 - Male, 2 - Female): ";
        std::cin >> gender;

        std::cout << "Enter hourly wage: ";
        std::cin >> hourlyWage;

        std::cout << "Enter overtime wage: ";
        std::cin >> overtimeHourlyWage;

        std::cout << "Enter standard of working hours: ";
        std::cin >> standardOfWorkingHours;

        try
        {
            HourlyWageWorker *worker = new HourlyWageWorker(fullName, gender, standardOfWorkingHours, hourlyWage, overtimeHourlyWage);
            return *worker;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}

std::ostream& operator<<(std::ostream &stream, const HourlyWageWorker& worker) {
    stream << "HourlyWageWorker {\n"
           << "fullName: " << worker.getFullName() << "\n"
           << "gender: " << worker.getGender() << "\n"
           << "normalHourlyWage: " << worker.getNormalHourlyWage() << "\n"
           << "overtimeHourlyWage: " << worker.getOvertimeHourlyWage() << "\n"
           << "standardOfWorkingHours: " << worker.getStandardOfWorkingHours() << "\n"
           << "}\n";

    return stream;
}
