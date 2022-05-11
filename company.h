
#include "vec.h"
#include "commission_wage_worker.h"
#include "hourly_wage_worker.h"
#include <cstring>
#include <stdexcept>
#include <string>

#ifndef LAB3_COMPANY_H
#define LAB3_COMPANY_H

enum class Recruation { Commission = 1, Hourly, Both, None };

inline std::istream &operator>>(std::istream &stream, Recruation &recruation) {
    stream >> recruation;
    return stream;
}

class Company {
private:
    Vector<CommissionWageWorker> commissionWageWorkers;
    Vector<HourlyWageWorker> hourlyWageWorkers;

    const std::size_t maxPrice = 3000;
    const std::size_t minPrice = 1000;
    const std::size_t workingCycle = 15;
    const std::size_t workingDay = 8;
    std::size_t workedDaysCount;

    void dismissHourlyWageWorker(std::string);
    void dismissCommissionWageWorker(std::string);

public:
    Company();

    ~Company();

    void recruitHourlyWageWorker(HourlyWageWorker &);

    void recruitCommissionWageWorker(CommissionWageWorker &);

    Recruation getRecruationStatus(std::string) const;

    const Vector<HourlyWageWorker>& getHourlyWageWorkers() const;

    const Vector<CommissionWageWorker>& getCommissionWageWorkers() const;

    void dismissWorkerByFullname(std::string, Recruation);

    std::size_t simulateWork(int);
};

inline Company::~Company() {
    delete &commissionWageWorkers;
    delete &hourlyWageWorkers;
}

#endif //LAB3_COMPANY_H
