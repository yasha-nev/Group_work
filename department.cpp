#include "department.h"

Department::Department()
{
    name = "something";
    free_places = 5;
    number_places = 5;
    index = 0;
}

//Getters
string Department::GetName()
{
    return name;
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

    cout << "Free Places: ";
    in >> exc.free_places;

    cout << "Number of places: ";
    in >> exc.number_places;

    exc.index = 0;
    //cout << "index:  ";
    //in >> exc.index;

    return in;
}
