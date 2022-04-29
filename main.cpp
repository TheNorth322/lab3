#include <iostream>
#include "main.h"
#include "hourly_wage_worker.h"
#include "commission_wage_worker.h"
#include "company.h"

typedef void (*MENU)(); // Массив указателей на функции

void menu(); // Меню для выбора типа сортировки

int main() {
	return 0;
}

HourlyWageWorker hireHourlyWageWorker() {
    HourlyWageWorker worker;
    std::string fullName;
    char gender;
    int hourlyWage, overtimeHourlyWage, standardOfWorkingHours;

    std::cout << "Введите ФИО сотрудника: ";
    std::cin >> fullName;
    worker.setFullName(fullName);

    while (1) {
        std::cout << "Выберите пол сотрудника(м/ж): ";
        std::cin >> gender;
        if (gender == 'м' || gender == 'ж') break;
        std::cout << "Неверный пол!" << std::endl;
    }
    if (gender == 'м') worker.setGender(Male);
    else worker.setGender(Female);

    while (1) {
        std::cout << "Введите почасовую оплату: ";
        std::cin >> hourlyWage;
        if (hourlyWage > 0) break;
        std::cout << "Неверная почасовая оплата!" << std::endl;
    }
    worker.setNormalHourlyWage(hourlyWage);

    while (1) {
        std::cout << "Введите оплату за переработку: ";
        std::cin >> overtimeHourlyWage;
        if (overtimeHourlyWage > 0) break;
        std::cout << "Неверная оплата за переработку!" << std::endl;
    }
    worker.setOvertimeHourlyWage(overtimeHourlyWage);

    while (1) {
        std::cout << "Введите норматив часов: ";
        std::cin >> standardOfWorkingHours;
        if (standardOfWorkingHours > 0) break;
        std::cout << "Неверный норматив часов: ";
    }
    
    return worker;
}

CommissionWageWorker hireCommissionWageWorker() {
    CommissionWageWorker worker;
    std::string fullName;
    char gender;
    int salary, percentage;

    std::cout << "Введите ФИО сотрудника: ";
    std::cin >> fullName;
    worker.setFullName(fullName);

    while (1) {
        std::cout << "Выберите пол сотрудника(м/ж): ";
        std::cin >> gender;
        if (gender == 'м' || gender == 'ж') break;
        std::cout << "Неверный пол!" << std::endl;
    }
    if (gender == 'м') worker.setGender(Male);
    else worker.setGender(Female);

    while (1) {
        std::cout << "Введите ЗП: ";
        std::cin >> salary;
        if (salary > 0) break;
        std::cout << "Неверная ЗП!" << std::endl;
    }
    worker.setSalary(salary);

    while (1) {
        std::cout << "Введите процент: ";
        std::cin >> percentage;
        if (percentage > 0) break;
        std::cout << "Неверный процент!" << std::endl;
    }
    worker.setPercentage(percentage);

    return worker;
}

void fireWorker(Company company) {
    std::string workerFullName;

    std::cout << "Введите ФИО сотрудника, которого хотите уволить: ";
    std::cin >> workerFullName;
    
    company.dismissWorkerByFullname(workerFullName);
}

void menu(Company company)
{
    int c;
    const char* options[] = { "1-Нанять сотрудника с почасовой оплатой труда", "2-Нанять сотрудника с комиссионной оплатой труда","3-Уволить сотрудникам по ФИО", "4-Моделировать работу", "5-ВЫХОД" };
    int i, num = 0,
        l = sizeof(options) / sizeof(char*); // Количество действий с программой
    MENU action[] = { hireHourlyWageWorker, hireCommissionWageWorker };
    
    while (1)
    {
        printf("----------РАБОТА С КОМПАНИЕЙ----------\n");
        for (i = 0; i < l; i++)
            printf("%s\n", options[i]);
        printf("Выберите номер опции: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
             action[c - 1]();
            printf("\nСотрудник успешно нанят\n");
            break;
        case 2:
            action[c - 1]();
            printf("\nСотрудник успешно нанят\n");
            break;
        case 3:
            std::string workerFullName;

            std::cout << "Введите ФИО сотрудника, которого хотите уволить: ";
            std::cin >> workerFullName;

            company.dismissWorkerByFullname(workerFullName);
            break;
        case 4:
            int days;

            std::cout << "Введите кол-во дней: ";
            std::cin >> days;
            company.simulateWork(days);
            break;
        case 5:
            return;
        default:
            printf("Ошибка! Введите число от 1 до %d", l);
            printf("\n");
            break;
        }
    }
    
}
