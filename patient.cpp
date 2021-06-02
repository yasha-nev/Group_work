#include "patient.h"

Patient::Patient()
{
    status = 0;
    department = -1;
}

Patient::Patient(string fn, string ln, string dis, string type_dis, int st, int dep, int tt, int tl)
{
    first_name = fn;
    last_name = ln;
    diagnosis = dis;
    type_of_disease = type_dis;
    status = st;
    department = dep;
    time_treat = tt;
    time_left = tl;
}

//getters реализация
string Patient::GetFirstName()
{
    return first_name;
}

string Patient::GetLastName()
{
    return last_name;
}

string Patient::GetDiagnosis()
{
    return diagnosis;
}

string Patient::GetTypeOfDisease()
{
    return type_of_disease;
}

int Patient::GetStatus()
{
    return status;
}

int Patient::GetDepartment()
{
    return department;
}

int Patient::GetTimeTreat()
{
    return time_treat;
}

int Patient::GetTimeLeft()
{
    return time_left;
}

//setters реализация
void Patient::SetFirstName(string a)
{
    if (a != ""){
        first_name = a;
    }
    else{
        cout << "Error" << endl;
    }
}

void Patient::SetLastName(string a)
{
    if (a != ""){
        last_name = a;
    }
    else{
        cout << "Error" << endl;
    }
}

void Patient::SetDiagnosis(string a)
{
    if (a != ""){
        diagnosis = a;
    }
    else{
        cout << "Error" << endl;
    }
}

void Patient::SetTypeOfDisease(string a)
{
    if (a != ""){
        type_of_disease = a;
    }
    else{
        cout << "Error" << endl;
    }
}

void Patient::SetStatus(int a)
{
    if (a >=-1 && a < 3){
        status = a;
    }
    else{
        cout << "Error" << endl;
    }
}
void Patient::SetDepartment(int a)
{
    if (a >= -1){
        department = a;
    }
    else{
        cout << "Error" << endl;
    }
}
void Patient::SetTimeTreat(int a)
{
    if (a >= 0){
        time_treat = a;
    }
    else{
        cout << "Error" << endl;
    }
}

void Patient::SetTimeLeft(int a)
{
    if (a >= 0){
        time_left = a;
    }
    else{
        cout << "Error" << endl;
    }
}

ostream& operator <<(ostream &out, const Patient &exc)
{
    out << "First Name: " << exc.first_name << endl;
    out << "Last Name: " << exc.last_name << endl;
    out << "Diagnosis: " << exc.diagnosis << endl;
    out << "Type of disease: " << exc.type_of_disease << endl;

    string str[4] = {"died", "not determined", "being treated", "healen"};

    out << "Status: " << str[exc.status + 1] << endl;
    out << "Department: " << exc.department << endl;
    out << "Time of treatment: " << exc.time_treat << endl;
    out << "Time left: " << exc.time_left << endl;
    return out;
}
istream& operator >> (istream &in, Patient &exc)
{
    string nm;
    cout << "First Name: ";
    in >> exc.first_name;

    cout << "Last Name: ";
    in >> exc.last_name;

    cout << "Diagnosis: ";
    in >> exc.diagnosis;

    cout << "Type of disease: ";
    in >> exc.type_of_disease;

    exc.status = 0;
    exc.department = -1;

    cout << "Time for treatment: ";
    in >> exc.time_treat;

    cout << "Time Left: ";
    in >> exc.time_left;
    return in;
}

