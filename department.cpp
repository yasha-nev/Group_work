#include "department.h"

Department::Department()
{
}

Department::Department(string nm, string dis[2], int fp, int np, int ix)
{
    name = nm;
    for (int i = 0; i < 2; i++){
        diseases[i] = dis[i];
    }
    free_places = fp;
    number_places = np;
    index = ix;
}

//Getters
string Department::GetName()
{
    return name;
}

string *Department::GetDiseases()
{
    return diseases;
}

int Department::GetFreePlaces()
{
    return free_places;
}

int Department::GetNumberPlaces()
{
    return number_places;
}

int Department::GetIndex()
{
    return index;
}

//Setters
void Department::SetName(string a)
{
    if (a != ""){
        name = a;
    }
    else{
        cout << "Error" << endl;
    }
}

void Department::SetDiseases(string a[])
{
    for (int i = 0; i < 2; i++){
        if (a[i] != ""){
            diseases[i] = a[i];
        }
        else{
           diseases[i] = "Error";
        }
    }
}

void Department::SetFreePlaces(int a)
{
    if (a>=0){
        free_places = a;
    }
    else{
        cout << "Error" << endl;
    }
}

void Department::SetNumberPlaces(int a)
{
    if (a>=0){
        number_places = a;
    }
    else{
        cout << "Error" << endl;
    }
}

void Department::SetIndex(int a)
{
    if (a>=0){
        index = a;
    }
    else{
        cout << "Error" << endl;
    }
}

ostream& operator <<(ostream &out, const Department &exc)
{
    out << "Name: " << exc.name << endl;
    out << "Diseases: ";
    for (int i = 0; i < 2; i++){
        out << exc.diseases[i] << " ";
    }
    out << endl;
    out << "Free Places: " << exc.free_places << endl;
    out << "Number of places: " << exc.number_places << endl;
    out << "index: " << exc.index << endl;
    return out;
}
istream& operator >> (istream &in, Department &exc)
{
    string nm;
    cout << "Name: ";
    in >> exc.name;

    cout << "diseases: ";
    for (int i = 0; i < 2; i++){
        in >> exc.diseases[i];
    }
    cout << "Free Places: ";
    in >> exc.free_places;

    cout << "Number of places: ";
    in >> exc.number_places;

    exc.index = 0;
    return in;
}
