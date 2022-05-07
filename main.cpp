#include <iostream>
#include <functional>
#include "main.h"
#include "hourly_wage_worker.h"
#include "commission_wage_worker.h"
#include "company.h"

int main() {
	Company company;
    menu(company);
    return 0;
}

void fireWorker(Company company, std::string fullName) {  
    Recruation state = company.checkRecruation(fullName);

    if (state == Recruation::None) {
        std::cout << "Worker wasn't found!" << std::endl;
        return;
    }

    if (state == Recruation::Both) {
        std::cout << "Worker has been found in both groups." << std::endl
                  << "Fire from? (1 - Hourly, 2 - Commission, 3 - Both)";
        
        std::cin >> state;
    }
    company.dismissWorkerByFullname(fullName, state);
}

void menu(Company company)
{
    int c;
    const char* options[] = { "1-Add hourly wage worker", "2-Add commission wage worker","3-Fire worker by full name", "4-Simulate work", "5-" };
    int i, num = 0,
        l = sizeof(options) / sizeof(char*);
    
    while (1)
    {
        printf("----------������ � ���������----------\n");
        for (i = 0; i < l; i++)
            printf("%s\n", options[i]);
        printf("�������� ����� �����: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            HourlyWageWorker hworker = enterHourlyWageWorker();
            company.recruitHourlyWageWorker(hworker);
            printf("\nWorker has been successfully recruited!\n");
            break;
        case 2:
            CommissionWageWorker cworker = enterCommissionWageWorker();
            company.recruitCommissionWageWorker(cworker);
            printf("\nWorker has been successfully recruited!\n");
            break;
        case 3:
            std::string fullName;
            std::cout << "Enter the full name of worker to fire: ";
            std::cin >> fullName;
            fireWorker(company, fullName);
            break;
        case 4:
            int days;

            std::cout << "������� ���-�� ����: ";
            std::cin >> days;
            company.simulateWork(days);
            break;
        case 5:
            return;
        default:
            printf("������! ������� ����� �� 1 �� %d", l);
            printf("\n");
            break;
        }
    }
    
}
