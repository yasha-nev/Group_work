#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string>

using namespace std;

class Patient // Пациент
{
private:
    string first_name; // Имя
    string last_name; // Фамилия
    string diagnosis; // Диагноз или травма
    int status; // статус, если 0 значит еще не лечится, если число, то это индекс отделения бальницы
    int time_left; // остаток времени, который ему дал бог

public:
    Patient();
    //прототипы, реализация в cpp файле

    //getters (функции получения переменных класса)
    string GetFirstName();
    string GetLastName();
    string GetDiagnosis();
    int GetStatus();
    int GetTimeLeft();

    //setters (функции изменения переменных класса)
    void SetFirstName(string a);
    void SetLastName(string a);
    void SetDiagnosis(string a);
    void SetStatus(int a);
    void SetTimeLeft(int a);

    friend ostream& operator << (ostream &out, const Patient &exc);
    friend istream& operator >> (istream &in, Patient &exc);

};

#endif // PATIENT_H
