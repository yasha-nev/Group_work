#ifndef MENU_H
#define MENU_H

#include "department.h"
#include "patient.h"
#include <iostream>
#include <fstream>
#include <vector>
#define C "cls"

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
    void HospitalAdmission();
    void StartGame();
};

#endif // MENU_H
