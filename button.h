#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <string>
using namespace std;

/*! \brief Класс Кнопки

 *   Создает кнопки
 *   Отрисовывает кнопки на экране
 *   Проверяет события взаимодействия с клавиатуро1
*/

class Button{
private:
    string titles[5] = {"PrintDepartment",
                        "PrintPatient",
                        "Hospital Admission",
                        "SkipTime",
                        "Exit"};  /**< массив строк: названия кнопок*/
    int y = 0;  /**< целое число: позиция курсора  */
public:
     /*! \brief Конструктор */
    Button();

     /*! \brief Чоздает выделеную кнопку
         \param [in] a номер название кнопки в массиве имен
         кнопка является выделеной, если позиция курсора соотвествует позиции кнопки
        */
    void SelectButton(int a);

     /*! \brief Создает не выделенную кнопку
         \param [in] a номер название кнопки в массиве имен
          кнопка является не выделенной, если позиция курсора не соотвествует позиции кнопки */
    void DisselectButton(int a);

     /*! \brief Рисует на экране все кнопки*/
    void PrintButtons();

     /*! \brief Перемещение курсора на позицию вверх*/
    void UpCursor();

     /*! \brief Перемещение курсора на позицию вниз*/
    void DownCursor();

     /*! \brief Проверка события, сделаного пользователем
         \param [in] n нажатая клавиша на клавиатуре пользователем*/
    int CheckEvent(int n);

     /*! \brief Положение курсора
         \return y целое число положение курсора */
    int GetY();
};

#endif // BUTTON_H
