#include "file.h"

File::File()
{

}

vector<Patient> *File::ReadPatient(char *f, vector<Patient> *p)
{
    fstream out(f, ios::in);
    if (!out.is_open()){
        return p;
    }
    string fname, lname, dis, type_dis;
    int size, status, dep, timet, timel;
    out >> size;
    for (int i=0; i<size; i++){
        out >> fname;
        out >> lname;
        out >> dis;
        out >> type_dis;
        out >> status;
        out >> dep;
        out >> timet;
        out >> timel;
        Patient pat(fname, lname, dis, type_dis, status, dep, timet, timel);
        p->push_back(pat);
    }
    out.close();
    return p;
}

void File::WritePatient(char *f, vector<Patient> p)
{
    fstream in(f, ios::out);
    if (!in.is_open()){
        return;
    }
    in << p.size() << endl;
    for (int i=0; i < p.size(); i++){
        in << p[i].GetFirstName() <<endl;
        in << p[i].GetLastName() << endl;
        in << p[i].GetDiagnosis() << endl;
        in << p[i].GetTypeOfDisease() << endl;
        in << p[i].GetStatus() << endl;
        in << p[i].GetDepartment() << endl;
        in << p[i].GetTimeTreat() << endl;
        in << p[i].GetTimeLeft() << endl;

    }
    in.close();
}

void File::CheckFiles()
{
    ifstream a("Patient//department_names.txt");
    ifstream b("Patient//diseases.txt");
    ifstream c("Patient//exclusive_people.txt");
    ifstream d("Patient//fitst_names.txt");
    ifstream e("Patient//hospital.txt");
    ifstream f("Patient//last_names.txt");
    ifstream g("Patient//type_dis.txt");
    if (!a.is_open() || b.is_open() || c.is_open() || d.is_open() || e.is_open() || f.is_open() || g.is_open()){
        a.close();
        b.close();
        c.close();
        d.close();
        e.close();
        f.close();
        g.close();
        return;
    }
    else{
        throw runtime_error("Error open files");
    }
}

vector<Department> *File::ReadDepartment(char *f, vector<Department> *d)
{
    fstream out(f, ios::in);
    if (!out.is_open()){
        return d;
    }
    string nm, dis[2];
    int fp, np, ix, size;
    out >> size;
    for (int i=0; i<size; i++){
        out >> nm;
        out >> dis[0] >> dis[1];
        out >> fp;
        out >> np;
        out >> ix;
        Department dep(nm, dis, fp, np, ix);
        d->push_back(dep);
    }
    out.close();
    return d;
}

void File::WriteDepartment(char *f, vector<Department> d)
{
    fstream in(f, ios::out);
    if (!in.is_open()){
        return;
    }
    in << d.size() << endl;
    for (int i=0; i < d.size(); i++){
        in << d[i].GetName() <<endl;
        in << d[i].GetDiseases()[0] << " "<< d[i].GetDiseases()[1] <<endl;
        in << d[i].GetFreePlaces() << endl;
        in << d[i].GetNumberPlaces() << endl;
        in << d[i].GetIndex() << endl;
    }
    in.close();
}
