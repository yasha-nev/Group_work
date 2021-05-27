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

vector<string> Department::GetDiseases()
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

void Department::Setdiseases()
{
    int n;
    string a;
    cout << "count of deseases";
    cin >> n;
    cout << "New diseases" << endl;
    diseases.clear();
    for (int i = 0; i < n; i++){
        cin >> a;
        if (a != ""){
            diseases.push_back(a);
        }
        else{
            i--;
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
    for (int i = 0; i < exc.diseases.size(); i++){
        out << exc.diseases[i];
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

    int n;
    string a;
    cout << "Count of diseases: ";

    in >> n;
    cout << "diseases: ";
    for (int i = 0; i < n; i++){
        in >> a;
        exc.diseases.push_back(a);
    }
    cout << "Free Places: ";
    in >> exc.free_places;

    cout << "Number of places: ";
    in >> exc.number_places;

    exc.index = 0;
    return in;
}
