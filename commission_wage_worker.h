#include <stdexcept>
#include <string>
#include <iostream>
#include "common.h"

#ifndef LAB3_COMMISSION_WAGE_WORKER_H
#define LAB3_COMMISSION_WAGE_WORKER_H

class CommissionWageWorker {
private:
    std::string fullName;
    Gender gender;
    int salary;
    int percentage;
    int goodsSoldSum;

public:
    CommissionWageWorker() {}

    CommissionWageWorker(std::string, Gender, int,
                         int );

    std::string getFullName() const;

    Gender getGender() const;

    int getSalary() const;

    int getPercentage() const;

    void sell(int);

    int calcWage();
};

CommissionWageWorker enterCommissionWageWorker();

std::ostream& operator<<(std::ostream &, const CommissionWageWorker &);

#endif //LAB3_COMMISSION_WAGE_WORKER_H
