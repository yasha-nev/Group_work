#include "menu.h"

Menu::Menu()
{}

void Menu::PrintPatient()
{
    for (int i = 0; i < p.size(); i++){
        cout << p[i] << endl;
    }
    return;
}

void Menu::PrintDepartment()
{
    for (int i = 0; i < d.size(); i++){
        cout << d[i] << endl;
    }
    return;
}

void Menu::AddPatient()
{
    Patient pat;
    cin >> pat;
    p.push_back(pat);
    cin.get();
}

void Menu::AddDepartment()
{
    Department dep;
    cin >> dep;
    dep.SetIndex(d.size());
    d.push_back(dep);
    cin.get();
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

void Menu::HospitalAdmission()
{
    int np, nd;
    cout << "number of patient: ";
    cin >> np;
    if ((np <0) || (np >= (int) p.size())){
        cout << "There is no such patient" << endl;
	cin.get();
	cin.get();
        return;
    }
    if (p[np].GetStatus() != 0){
        cout << "The patient is already on another list" << endl;
	cin.get();
	cin.get();       
	return;
    }

    cout << p[np] << endl;
    cout << "number of department: ";
    cin >> nd;
    if ((nd <0) || (nd >=  d.size())){
        cout << "There is no such department" << endl;
	cin.get();
	cin.get();
        return;
    }

    if (d[nd].GetFreePlaces() > 0){
        bool a = 0;
        for (int i=0; i < d[nd].GetDiseases().size(); i++){
            if (p[np].GetTypeOfDisease() == d[nd].GetDiseases()[i]){
                a = 1;
            }
        }
        if (a == 1){
            p[np].SetDepartment(nd);
            p[np].SetStatus(1);
            d[nd].SetFreePlaces(d[nd].GetFreePlaces()-1);
            cout << "Patient admitted" << endl;
	    cin.get();
	    cin.get();
        }
        else{
	    
            cout << "This department cannot admit this patient" << endl;
	    cin.get();
	    cin.get();
            return;
        }
    }
    else{
        cout << "there are not free places";
	cin.get();
	cin.get();
        return;
    }
}

void Menu::StartGame()
{

    ifstream out;
    out.open("./hospital.txt");
    string s;

    if (out){
        int t = 0;
        int size;
        out >> size;
        while (t != size){
            system(C);
            cout << "                   HOSPITAL GAME               " << endl;
            for (int i = 0; i<t; i++){
                getline(out, s);
                cout << s << endl;
            }
            out.seekg('\n');
            t++;
        }
    }
    else{
        cout << "Error" << endl;
    }

    cout << "                   START GAME               " << endl;
    out.close();
    cin.get();
    return;


}
int Menu::getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}
