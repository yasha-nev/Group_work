#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <string>
using namespace std;

class Button{
private:
    string titles[7] = {"PrintDepartment",
                        "PrintPatient",
                        "AddPatient",
                        "AddDepartment",
                        "Hospital Admission",
                        "SkipTime",
                        "Exit"};
    int y = 0;
public:
    Button();
    void SelectButton(int a);
    void DisselectButton(int a);
    void PrintButtons();
    void UpCursor();
    void DownCursor();
    int GetY();
};

#endif // BUTTON_H
