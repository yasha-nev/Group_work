#include "patient.h"

Patient::Patient()
{

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

void Patient::SetStatus(int a)
{
    if (a >=-1){
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
    out << "Status: " << exc.status << endl;
    out << "Department" << exc.department << endl;
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

    //cout << "Status:  ";
    //in >> exc.status;
    exc.status = 0;
    exc.department = -1;

    cout << "Time for treatment: ";
    in >> exc.time_treat;

    cout << "Time Left: ";
    in >> exc.time_left;
    return in;
}

