#include <iostream>
#include "array.h"
#include "patient.h"
#include "department.h"

using namespace std;

int main()
{
    Array<Patient> p;
    Array<Department> d;

    p.Push();
    cout << endl;
    cout << endl;
    p.Push();
    cout << endl;
    cout << endl;
    p.Print();
    p.Delete(1);
    cout << endl;
    cout << endl;
    p.Print();
    return 0;
}
