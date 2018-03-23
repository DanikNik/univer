#pragma once
#define min_age 6574
#define max_age 23742
#include <iostream>
#include <fstream>
#include <string.h>
#include <cmath>
using namespace std;

double get_day(int*);

struct competitor{
    string surname; //фамилия
    string name;    //имя
    string sec_name;//отчество
    string birth_date;
    int * birth_date_arr; //дата рождения - выделить память int [3]
    string sex; //male, female;
    int results[4]; //результаты по каждому из 4 соревнований
    int sum; // суммарный результат
    int age;
};

bool check_set(competitor*, competitor, int);

int * get_date();

bool is_date_correct(int*);

competitor * get_competitors(int, int*);

void sort(competitor*, int);

void fill_db(string, competitor*, int*, int);
