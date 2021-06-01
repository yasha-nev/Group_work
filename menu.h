#ifndef MENU_H
#define MENU_H

#include "department.h"
#include "patient.h"
#include "file.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <cstdlib>

using namespace std;

class Menu
{
private:
    int time = 0;
    int week = 0;
    int healen = 0;
    int died = 0;
    File f;

    vector <Patient> p;
    vector <Department> d;

public:
    Menu();
    int GetTime();
    int GetHealen();
    int GetDied();
    void PrintPatient();
    void PrintDepartment();
    void AddPatient();
    void AddDepartment();
    void DaySkip();
    void HospitalAdmission();
    void StartGame(char *argv[]);
    void finalGame(char *argv[]);
    void FreePatient();
    int getRandomNumber(int min, int max);
    int getch(void);
};

#endif // MENU_H
