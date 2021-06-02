#ifndef MENU_H
#define MENU_H

#include "department.h"
#include "patient.h"
#include "file.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <cstdlib>

using namespace std;
/*! \brief Класс для работы с базой данных */

class Menu
{
private:
    int time; /**< целое число: количество днейа */
    int week; /**< целое число: количество недель */
    int healen; /**< целое число: количество вылеченых пациентов */
    int died; /**< целое число: количество умерших пациентов */
    File f; /**< экземпляр класса File для работы с файлами, в которых находится база данных*/
    vector <Patient> p; /**< Массив экземпляров класса Patient пациенты, которые проходят лечение в больнице */
    vector <Department> d; /**< Массив экземпляра класса Department отделения больницы */

public:
    /*! \brief Конструктор */
    Menu();
    int GetTime();
    int GetHealen();
    int GetDied();

    /*! \brief Выводит на экран всех пациентов в больницы*/
    void PrintPatient();

    /*! \brief Выводит на экран все отделения больницы*/
    void PrintDepartment();

    /*! \brief Добавляет нового пациента в больницу*/
    void AddPatient();

    /*! \brief Добавляет новое отделение в больницу*/
    void AddDepartment();

    /*! \brief Смещение по времени*/
    void DaySkip();

    /*! \brief Добавлегние пациента в больницу*/
    void HospitalAdmission();

    /*! \brief Начало игры
        \param [in] *argv[] указатель на массив с передаными файлами
        Печать логотипа, стартовое меню игры
        Проверка целостности файлов игры
        Чтение базы данных из файла
    */
    void StartGame(char *argv[]);

    /*! \brief Конец игры
     *  \param [in] *argv[] указатель на массив с передаными файлами
        Запись базы данных в файлы
    */
    void finalGame(char *argv[]);
    /*! \brief Выписка пациента из больницы
        Проверка пациентов на статус,
        если пациент имеет статус выличился, то подлежит выписке
        если пациент имеет статус умер, то подлежит переводу в морг
    */
    void FreePatient();
    /*! \brief Получение рандомного числа в диапазоне
        \param [in] min - минимальное число в диапазоне
        \param [in] max - максимальное число в диапазоне
        \return целое рандомное число в диапозоне между min и max
    */
    int getRandomNumber(int min, int max);

    /*! \brief функция ввода в терминал без echo*/
    int getch(void);
};

#endif // MENU_H
