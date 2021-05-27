#include <iostream>
#include "menu.h"
#include "button.h"
#define C "clear"

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
        n = menu.getch();
        switch(n){
            case(65):
                b.DownCursor();
                break;
            case(66):
                b.UpCursor();
                break;
            case(10):
                {
                    int k = b.GetY();
                    switch (k) {
                        case(0):
                            system(C);
                            menu.PrintDepartment();
                            {
                            	menu.getch();
                            }
                            break;
                        case(1):
                            system(C);
                            menu.PrintPatient();
                            menu.getch();
                            break;
                        case(2):
                            system(C);
                            menu.AddPatient();
			    menu.getch();
                            break;
                        case(3):
                            system(C);
                            menu.AddDepartment();
		 	    menu.getch();
                            break;
                        case(4):
                            system(C);
                            menu.HospitalAdmission();
                            break;
                        case(5):
                            system(C);
                            menu.DaySkip();
			    menu.getch();
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
