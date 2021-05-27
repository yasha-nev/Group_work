#include "button.h"

Button::Button()
{

}

void Button::SelectButton(int a)
{
    int size = (20 - titles[a].size())/2;
    int m = 0;
    if (titles[a].size() % 2 != 0){
        m = 1;
    }
    cout <<" --------------------" << endl;
    cout <<"|                    |" << endl;
    cout << "|";

    for (int i = 0; i < size + m; i++){
        cout << " ";
    }
    cout << titles[a];
    for (int i = 0; i < size; i++){
        cout << " ";
    }
    cout << "|" << endl;
    cout <<"|                    |" << endl;
    cout <<" --------------------" << endl;
}

void Button::DisselectButton(int a)
{
    int size = (20 - titles[a].size())/2;
    int m = 0;
    if (titles[a].size() % 2 != 0){
        m = 1;
    }

    cout <<"|                    |" << endl;
    cout << "|";

    for (int i = 0; i < size + m; i++){
        cout << " ";
    }
    cout << titles[a];
    for (int i = 0; i < size; i++){
        cout << " ";
    }
    cout << "|" << endl;
    cout <<"|                    |" << endl;
}

void Button::PrintButtons()
{
    for (int i = 0; i<7; i++){
        if (y == i){
            SelectButton(i);
        }
        else{
            DisselectButton(i);
        }
    }
}

void Button::UpCursor()
{
    if (y + 1 < 7){
        y++;
    }
}

void Button::DownCursor()
{
    if (y - 1 > -1){
        y--;
    }
}

int Button::GetY(){
    return y;
}
