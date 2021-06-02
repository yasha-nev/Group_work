#ifndef FILE_H
#define FILE_H
#include "patient.h"
#include "department.h"
#include <vector>
#include <fstream>

using namespace std;

class File
{
public:
    File();
    vector <Patient> *ReadPatient(char *f, vector<Patient> *p);
    vector <Department> *ReadDepartment(char *f, vector<Department> *d);
    void WriteDepartment(char *f, vector<Department> d);
    void WritePatient(char *f, vector<Patient> p);
    void CheckFiles();
};

#endif // FILE_H
