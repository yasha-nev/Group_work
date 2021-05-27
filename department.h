#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Department // отделение больницы
{
private:
    string name; // название отделение
    vector <string> diseases; // болезни, которые лечит данное отделение
    int free_places; //количество свободных мест
    int number_places; //всего мест
    int index; // индекс

public:
    Department();

    //Getters
    string GetName();
    vector<string> GetDiseases();
    int GetFreePlaces();
    int GetNumberPlaces();
    int GetIndex();

    //Setters
    void SetName(string a);
    void Setdiseases();
    void SetFreePlaces(int a);
    void SetNumberPlaces(int a);
    void SetIndex(int a);

    friend ostream& operator << (ostream &out, const Department &exc);
    friend istream& operator >> (istream &in, Department &exc);

};

#endif // DEPARTMENT_H
