#include "menu.h"

Menu::Menu()
{

}

void Menu::PrintPatient()
{
    for (int i = 0; i < p.size(); i++){
        cout << p[i] << endl;
    }
}

void Menu::PrintDepartment()
{
    for (int i = 0; i < d.size(); i++){
        cout << d[i] << endl;
    }
}
