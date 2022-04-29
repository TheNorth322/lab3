#include <iostream>
#include "main.h"
#include "hourly_wage_worker.h"
#include "commission_wage_worker.h"
#include "company.h"

typedef void (*MENU)(); // ������ ���������� �� �������

void menu(); // ���� ��� ������ ���� ����������

int main() {
	return 0;
}

HourlyWageWorker hireHourlyWageWorker() {
    HourlyWageWorker worker;
    std::string fullName;
    char gender;
    int hourlyWage, overtimeHourlyWage, standardOfWorkingHours;

    std::cout << "������� ��� ����������: ";
    std::cin >> fullName;
    worker.setFullName(fullName);

    while (1) {
        std::cout << "�������� ��� ����������(�/�): ";
        std::cin >> gender;
        if (gender == '�' || gender == '�') break;
        std::cout << "�������� ���!" << std::endl;
    }
    if (gender == '�') worker.setGender(Male);
    else worker.setGender(Female);

    while (1) {
        std::cout << "������� ��������� ������: ";
        std::cin >> hourlyWage;
        if (hourlyWage > 0) break;
        std::cout << "�������� ��������� ������!" << std::endl;
    }
    worker.setNormalHourlyWage(hourlyWage);

    while (1) {
        std::cout << "������� ������ �� �����������: ";
        std::cin >> overtimeHourlyWage;
        if (overtimeHourlyWage > 0) break;
        std::cout << "�������� ������ �� �����������!" << std::endl;
    }
    worker.setOvertimeHourlyWage(overtimeHourlyWage);

    while (1) {
        std::cout << "������� �������� �����: ";
        std::cin >> standardOfWorkingHours;
        if (standardOfWorkingHours > 0) break;
        std::cout << "�������� �������� �����: ";
    }
    
    return worker;
}

CommissionWageWorker hireCommissionWageWorker() {
    CommissionWageWorker worker;
    std::string fullName;
    char gender;
    int salary, percentage;

    std::cout << "������� ��� ����������: ";
    std::cin >> fullName;
    worker.setFullName(fullName);

    while (1) {
        std::cout << "�������� ��� ����������(�/�): ";
        std::cin >> gender;
        if (gender == '�' || gender == '�') break;
        std::cout << "�������� ���!" << std::endl;
    }
    if (gender == '�') worker.setGender(Male);
    else worker.setGender(Female);

    while (1) {
        std::cout << "������� ��: ";
        std::cin >> salary;
        if (salary > 0) break;
        std::cout << "�������� ��!" << std::endl;
    }
    worker.setSalary(salary);

    while (1) {
        std::cout << "������� �������: ";
        std::cin >> percentage;
        if (percentage > 0) break;
        std::cout << "�������� �������!" << std::endl;
    }
    worker.setPercentage(percentage);

    return worker;
}

void fireWorker(Company company) {
    std::string workerFullName;

    std::cout << "������� ��� ����������, �������� ������ �������: ";
    std::cin >> workerFullName;
    
    company.dismissWorkerByFullname(workerFullName);
}

void menu(Company company)
{
    int c;
    const char* options[] = { "1-������ ���������� � ��������� ������� �����", "2-������ ���������� � ������������ ������� �����","3-������� ����������� �� ���", "4-������������ ������", "5-�����" };
    int i, num = 0,
        l = sizeof(options) / sizeof(char*); // ���������� �������� � ����������
    MENU action[] = { hireHourlyWageWorker, hireCommissionWageWorker };
    
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
             action[c - 1]();
            printf("\n��������� ������� �����\n");
            break;
        case 2:
            action[c - 1]();
            printf("\n��������� ������� �����\n");
            break;
        case 3:
            std::string workerFullName;

            std::cout << "������� ��� ����������, �������� ������ �������: ";
            std::cin >> workerFullName;

            company.dismissWorkerByFullname(workerFullName);
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
