#include "menu.h"

Menu::Menu()
{}

int Menu::GetTime()
{
    return time;
}

int Menu::GetHealen()
{
    return healen;
}

int Menu::GetDied()
{
    return died;
}

void Menu::PrintPatient()
{
    for (int i = 0; i < p.size(); i++){
        cout << "--------------------" << endl;
        cout << p[i] << endl;
        cout << "--------------------" << endl;
    }
    return;
}

void Menu::PrintDepartment()
{
    for (int i = 0; i < d.size(); i++){
        cout << "--------------------" << endl;
        cout << d[i] << endl;
        cout << "--------------------" << endl;
    }
    return;
}

void Menu::AddPatient()
{
    Patient pat;
    ifstream first_names("Patients//first_names.txt");
    ifstream last_names("Patients//last_names.txt");
    ifstream disease("Patients//diseases.txt");
    int count_fn, count_ln, count_dis;
    string lname, fname, dis, type_dis;
    int randp = getRandomNumber(0, 10);

    if (randp < 2){
        ifstream exc_paient("Patients//exclusiv_people.txt");
        int count_exc;
        exc_paient >> count_exc;
        randp = getRandomNumber(0, count_exc -1);
        for (int i = 0; i < randp; i++){
            exc_paient >> fname >> lname >> dis >> type_dis;

        }
        exc_paient >> fname >> lname >> dis >> type_dis;
        exc_paient.close();


    }
    else{
        first_names >> count_fn;
        int r = getRandomNumber(1, count_fn);
        for (int i = 0; i < r; i ++){
            first_names >> fname;
        }
        first_names >> fname;

        last_names >> count_ln;
        r = getRandomNumber(1, count_ln);
        for (int i = 0; i < r; i ++){
            last_names >> lname;
        }
        last_names >> lname;

        disease >> count_dis;
        r = getRandomNumber(1, count_dis);
        for (int i = 0; i < r; i ++){
            disease >> dis >> type_dis;
        }
        disease >> dis >> type_dis;

    }
    pat.SetFirstName(fname);
    pat.SetLastName(lname);
    pat.SetDiagnosis(dis);
    pat.SetTypeOfDisease(type_dis);
    pat.SetTimeTreat(getRandomNumber(14, 21));
    pat.SetTimeLeft(getRandomNumber(14, 21));

    p.push_back(pat);
    first_names.close();
    last_names.close();
    disease.close();
}

void Menu::AddDepartment()
{
    Department dep;
    ifstream disease("Patients//type_dis.txt");
    ifstream names("Patients//department_names.txt");
    string dis[3];
    string name;
    int count_dis, count_n, r;

    disease >> count_dis;
    r = getRandomNumber(1, count_dis - 1);
    for (int j = 0; j < r; j++){
        disease >> dis[0]>>dis[1];
    }
    disease  >> dis[0] >> dis[1];

    names >> count_n;
    r = getRandomNumber(1, count_n - 1);
    for (int j = 0; j < r; j++){
        names >> name;
    }
    names  >> name;

    disease.seekg(0, ios::beg);
    disease >> count_dis;

    r = getRandomNumber(2, 4);
    dep.SetDiseases(dis);
    dep.SetName(name);
    dep.SetNumberPlaces(r);
    dep.SetFreePlaces(r);
    dep.SetIndex(d.size());


    disease.close();
    d.push_back(dep);
}

void Menu::DaySkip()
{
    int queue_patient;
    int t = getRandomNumber(1, 7);
    cout << "Skip " <<  t << " days" << endl;
    for(int i = 0; i < p.size(); i++){
        if(p[i].GetStatus() == 1){
            int l;
            l = p[i].GetTimeTreat() - t;
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
            l = p[i].GetTimeLeft() - t;
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

    queue_patient = getRandomNumber(1, 3);

    cout << "You get " << queue_patient << " new patient" << endl;
    for (int i = 0; i < queue_patient; i++){
        AddPatient();
    }
    if (time + t - (week * 7) > 7){
        week++;
        int r = getRandomNumber(0, 10);
        if (r <= 5){
            cout << "You get new department" << endl;
            AddDepartment();
        }
    }
    FreePatient();
    time += t;
}

void Menu::HospitalAdmission()
{
    int np = 0;
    int nd = 0;
    int cursor = 0;
    vector <int> new_d;

    while (cursor != 10){
        system("clear");
        system("clear");
        cout << np << endl;
        cout << "--------------------" << endl;
        cout << p[np] << endl;
        cout << "--------------------" << endl;
        cursor = getch();
        if (cursor == 65 && np+1 < p.size()){
            np++;
        }
        else if (cursor == 66 && np-1 > -1){
            np--;
        }

    }

    if (p[np].GetStatus() != 0){
        cout << "The patient is already on another list" << endl;
        getch();
        return;
    }

    for (int i = 0; i < d.size(); i++){
        bool t = 0;
        for (int j = 0; j < 2; j++){
            if (p[np].GetTypeOfDisease() == d[i].GetDiseases()[j]){
                t = 1;
                break;
            }
        }
        if (t == 1){
            new_d.push_back(d[i].GetIndex());
        }
    }
    if (new_d.size() == 0){
        cout << "there no departments";
        getch();
        return;
    }
    cursor = 0;
    while (cursor != 10){
        system("clear");
        system("clear");
        cout << "--------------------" << endl;
        cout << d[new_d[nd]] << endl;
        cout << "--------------------" << endl;
        cursor = getch();
        if (cursor == 65 && nd+1 < new_d.size()){
            nd++;
        }
        else if (cursor == 66 && nd-1 > -1){
            nd--;
        }

    }

    if (d[new_d[nd]].GetFreePlaces() > 0){
        p[np].SetDepartment(d[new_d[nd]].GetIndex());
        p[np].SetStatus(1);
        d[new_d[nd]].SetFreePlaces(d[new_d[nd]].GetFreePlaces()-1);
        cout << "Patient admitted";
        getch();
        return;
    }
    else{
        cout << "there are not free places";
        getch();
        return;
    }
}

void Menu::StartGame(char *argv[])
{
    f.CheckFiles();
    ifstream out;
    out.open("Patients//hospital.txt");
    string s;

    if (out){
        int size;
        out >> size;

        cout << "                   HOSPITAL GAME               " << endl;
        for (int i =0; i < size; i++){
            getline(out, s);
            cout << s << endl;
        }
    }
    else{
        cout << "Error" << endl;
    }

    cout << "                   START GAME               " << endl;
    out.close();

    f.ReadPatient(argv[1], &p);
    f.ReadDepartment(argv[2], &d);
    if (p.empty() && d.empty()){
        for (int i = 0; i < 3; i++){
            AddDepartment();
            AddPatient();
        }
    }

    getch();
    return;

}

void Menu::finalGame(char *argv[])
{
    f.WritePatient(argv[1], p);
    f.WriteDepartment(argv[2], d);
}

void Menu::FreePatient()
{
    cout << "Was healen" << endl;
    bool n = 1;
    while (n == 1){
        n = 0;
        for (int i = 0; i < p.size(); i++){
            if (p[i].GetStatus() == 2){
                cout << p[i] << endl;
                int k = d[p[i].GetDepartment()].GetFreePlaces();
                d[p[i].GetDepartment()].SetFreePlaces(k+1);
                healen++;
                p.erase(p.begin() + i);
                n = 1;
            }
        }
    }

    cout << "Was died" << endl;
    n = 1;
    while (n == 1){
        n = 0;
        for (int i = 0; i < p.size(); i++){
            if (p[i].GetStatus() == -1){
                cout << p[i] << endl;
                died++;
                p.erase(p.begin() + i);
                n = 1;
            }
        }
    }

}

int Menu::getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
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
