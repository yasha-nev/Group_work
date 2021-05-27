#include "menu.h"

Menu::Menu()
{}

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

void Menu::AddPatient()
{
    Patient pat;
    cin >> pat;
    p.push_back(pat);
}

void Menu::AddDepartment()
{
    Department dep;
    cin >> dep;
    dep.SetIndex(d.size());
    d.push_back(dep);
}

void Menu::DaySkip()
{
    int d;  cout << "Сколько скипнуть дней-> " << endl;  cin >> d;
    for(int i = 0; i < p.size();i++){
        if(p[i].GetStatus() == 1){
            int l;
            l = p[i].GetTimeTreat() - d;
            if(l < 0){
                l = 0;
                p[i].SetTimeTreat(l);
                p[i].SetStatus(2);
            }
            else{
                p[i].SetTimeTreat(l);
            }
        }
        if(p[i].GetStatus() == 0){
            int l;
            l = p[i].GetTimeLeft() - d;
            if(l <= 0){
                l = 0;
                p[i].SetTimeLeft(l);
                p[i].SetStatus(-1);
            }
            else{
                p[i].SetTimeLeft(l);

        }
    }
    }
}
