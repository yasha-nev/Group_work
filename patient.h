#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string>

using namespace std;

/*! \brief Класс Пациента*/

class Patient // Пациент
{
private:

    string first_name; /**< строка: имя пациента */
    string last_name; /**< строка: фамилия пациентаr */
    string diagnosis; /**< строка: диагноз */
    string type_of_disease; /**< строка: классификация болезни по типу травмы */
    int status; /**<  целое число: статус состояние пациента*/
    int department; /**< целое число: отделение к которому относится, -1 - не определен в отделение */
    int time_treat; /**< целое число: время отведенное на лечение */
    int time_left; /**< целое число: время до смерти при отсутсвии лечения */

public:
    /*! \brief Конструктор */
    Patient();

    /*! \brief Конструктор
        \param [in] fname строка: имя
        \param [in] lname строка: фамилия
        \param [in] dis строка: диагноз
        \param [in] type_dis строка: тип диагноза по типу травмы
        \param [in] st целое число: статус пациента
        \param [in] dep целое число: номер отделение больницы
        \param [in] timet целое число: отведенное время на лечение
        \param [in] timel целое число: время до смерти
    */
    Patient(string fname, string lname, string dis, string type_dis, int st, int dep, int timet, int timel);

    string GetFirstName();
    string GetLastName();
    string GetDiagnosis();
    string GetTypeOfDisease();
    int GetStatus();
    int GetDepartment();
    int GetTimeTreat();
    int GetTimeLeft();

    void SetFirstName(string fname);
    void SetLastName(string lname);
    void SetDiagnosis(string dis);
    void SetTypeOfDisease(string type_dis);
    void SetStatus(int st);
    void SetDepartment(int dep);
    void SetTimeTreat(int timet);
    void SetTimeLeft(int timel);

    friend ostream& operator << (ostream &out, const Patient &exc);
    friend istream& operator >> (istream &in, Patient &exc);

};

#endif // PATIENT_H
