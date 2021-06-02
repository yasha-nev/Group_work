#ifndef FILE_H
#define FILE_H
#include "patient.h"
#include "department.h"
#include <vector>
#include <fstream>

using namespace std;
/*! \brief Класс для работы с файлами базы данных */
class File
{
public:
    /*! \brief Конструктор*/

    File();
    /*! \brief Чтение данных пациентов из файла
        \param [in] *f указатель на файл
        \param [in] *p указатель на массив пациентов
        \return vector<Patient> *p указатель на массив пациентов*/
    vector <Patient> *ReadPatient(char *f, vector<Patient> *p);

    /*! \brief Чтение данных отделений больницы из файла
        \param [in] *f указатель на файл
        \param [in] *p указатель на массив отделений
        \return *d указатель на массив Отделений*/
    vector <Department> *ReadDepartment(char *f, vector<Department> *d);

    /*! \brief Запись данных отделений в файл
        \param [in] *f указатель на файл
        \param [in] *p указатель на массив отделений*/
    void WriteDepartment(char *f, vector<Department> d);

     /*! \brief Запись данных пациентов
         \param [in] *f указатель на файл
         \param [in] *p указатель на массив пациентов*/
    void WritePatient(char *f, vector<Patient> p);

    /*! \brief Проверка наличия и целостности всех файлов*/
    void CheckFiles();
};

#endif // FILE_H
