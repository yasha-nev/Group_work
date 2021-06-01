#include <iostream>
#include "menu.h"
#include "button.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 3){
        return 0;
    }

    srand(time(nullptr));

    int n;
    Button button;
    Menu menu;
    menu.StartGame(argv);
    while(true){
        system("clear");
        system("clear");
        cout << "Days: " << menu.GetTime() << " Healen: " << menu.GetHealen() << " Died: " << menu.GetDied() << endl;

        button.PrintButtons();
        n = menu.getch();
        button.CheckEvent(n);

        if (menu.GetDied() > 10){
            cout << "Game ove" << endl;
            cout << "You lived "<< menu.GetTime() << "days" << endl;
            return 0;
        }

        if (n == 10){
            int k = button.GetY();
            switch (k) {
                case(0):
                    system("clear");
                    system("clear");
                    menu.PrintDepartment();
                    menu.getch();
                    break;

                case(1):
                    system("clear");
                    system("clear");
                    menu.PrintPatient();
                    menu.getch();
                    break;

                case(2):
                    system("clear");
                    system("clear");
                    menu.HospitalAdmission();
                    break;

                case(3):
                    system("clear");
                    system("clear");
                    menu.DaySkip();
                    menu.getch();
                    break;

                case(4):
                    menu.finalGame(argv);
                    return 0;
            }
        }
    }
}
