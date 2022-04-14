#pragma once
#include <iostream>
#include <string>
using namespace std;
const int WORKERS_AMOUNT = 25;

class Hourly_wage_workers {
    private:
        string full_name;
        string gender;
        int hours; // отработанные часы
        int hourly_payment; // оплата за час
        int hours_to_work; // часы работы
        int additional_hours_payment; // оплата за переработку
    public:
        void set_full_name(string);
        void set_gender(string);
        void set_hourly_payment(int);
        void set_working_hours(int);
        void set_additional_payment(int);
        void work(string, string, int, int, int, int);
        int calculate_salary(int, int, int, int);
};

class Commission_wage_workers {
    private:
        string full_name;
        string gender;
        int wage; // оклаж
        int percentage; // процент с продаж
        int products_sold; // кол-во продаж
    public:
        void set_full_name(string);
        void set_gender(string);
        void set_wage(int);
        void set_percentage(int);
        void sell_products(int);
        //int calculate_salary(int, int, int, int);
};

class Company {
    Hourly_wage_workers workers[WORKERS_AMOUNT]; // массив для сотрудников с почасовой оплатой  труда
    Commission_wage_workers cworkers[WORKERS_AMOUNT]; // массив для сотрудников с комиссионной оплатой труда
    int days_after_payday; // счетчик дней после ЗП
};