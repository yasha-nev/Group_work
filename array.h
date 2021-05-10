#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;

template <class  T>

class Array
{
private:
    int size;
    T*arr;

public:
    Array(){
        size = 0;
    }
    ~Array()
    {
        delete[] arr;
    }
    int GetSize(){
        return size;
    }
    void Push(){

        T *new_arr = new T[size + 1];

        for (int i = 0; i<size; i++){
            new_arr[i] = arr[i];
        }

        cin >> new_arr[size];

        if (size != 0){
            delete [] arr;
        }

        size++;
        arr = new_arr;



    }
    void Print(){
        for (int i = 0; i < size; i++){
            cout << arr[i] << endl;
        }
    }

    void Delete(int index){
        if (index < 0 || index >= size){
            return;
        }
        for (int i = index; i < size-1; i++){
            arr[i] = arr[i+1];
        }
        T*new_arr = new T[size - 1];

        for (int i = 0; i < size - 1; i++){
            new_arr[i] = arr[i];
        }
        if (size != 0){
            delete[] arr;
        }
        arr = new_arr;
        size--;
    }
};

#endif // ARRAY_H
