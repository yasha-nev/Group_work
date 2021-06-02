#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*! \brief Класс отделение больницы*/

class Department
{
private:
    string name; /**< строка: название отделения */
    string diseases[2]; /**< массив строк: болезни, которые может лечить данное отделение */
    int free_places; /**< целое число: количество свободных мест*/
    int number_places; /**< целое число: количество мест */
    int index; /**< целое число: номер тделения */

public:
    /*! \brief конструктор */
    Department();

    /*! \brief Конструктор
        \param [in] nm строка: название
        \param [in] dis массив строк: болезни
        \param [in] fplace целое число: количество свободных мест
        \param [in] nplace целое число: количество мест
        \param [in] ind целое число: номер отделения
    */
    Department(string nm, string dis[2], int freep, int numberp, int ind);

    //Getters
    string GetName();
    string *GetDiseases();
    int GetFreePlaces();
    int GetNumberPlaces();
    int GetIndex();

    //Setters
    void SetName(string nm);
    void SetDiseases(string dis[]);
    void SetFreePlaces(int freep);
    void SetNumberPlaces(int freen);
    void SetIndex(int ind);

    friend ostream& operator << (ostream &out, const Department &exc);
    friend istream& operator >> (istream &in, Department &exc);

};

#endif // DEPARTMENT_H
