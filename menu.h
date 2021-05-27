#ifndef MENU_H
#define MENU_H

#include "department.h"
#include "patient.h"
#include <iostream>
#include <vector>

using namespace std;

class Menu
{
private:
    vector <Patient> p;
    vector <Department> d;

public:
    Menu();
    void PrintPatient();
    void PrintDepartment();
    void AddPatient();
    void AddDepartment();
    void DaySkip();
};

#endif // MENU_H
