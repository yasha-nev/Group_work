#ifndef MENU_H
#define MENU_H

#include "department.h"
#include "patient.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#define C "clear"

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
    int getch(void);
};

#endif // MENU_H
