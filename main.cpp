#include <iostream>
#include "menu.h"
#include "button.h"
#include <conio.h>
#define C "cls"

using namespace std;

int main()
{
    bool a = 0;
    int n;
    Button b;
    Menu menu;
    menu.StartGame();
    while( a == 0){
        system(C);
        b.PrintButtons();
        n = getch();
        switch(n){
            case(72):
                b.DownCursor();
                break;
            case(80):
                b.UpCursor();
                break;
            case(13):
                {
                    int k = b.GetY();
                    switch (k) {
                        case(0):
                            system(C);
                            menu.PrintDepartment();
                            {
                            system("pause");
                            }
                            break;
                        case(1):
                            system(C);
                            menu.PrintPatient();
                            {
                            system("pause");
                            }
                            break;
                        case(2):
                            system(C);
                            menu.AddPatient();
                            break;
                        case(3):
                            system(C);
                            menu.AddDepartment();
                            break;
                        case(4):
                            system(C);
                            menu.HospitalAdmission();
                            break;
                        case(5):
                            system(C);
                            menu.DaySkip();
                            break;

                        case(6):
                            return 0;
                            break;
                    }
                }
                break;
        }
    }
}
