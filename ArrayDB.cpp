#include "ArrayDB.h"

ArrayDB::ArrayDB(){
    for (int i = 0; i < MAX2; i++)
    {
        Array[i] = -1;
    }
    size = 0;
}

bool ArrayDB::push(int Num){
    if (size < MAX2)
    {
        Array[size++] = Num;
        return true;
    }
    else
    {
        cout << "stack overflow" << endl;
        return false;
    }
}

int ArrayDB::pop(int Num){
    int pos = -1, num;
    for (int i = 0; i < size; i++)
    {
        if (Array[i] == Num)
        {
            num = Array[i];
            pos = i;
            break;
        }
        else if (Array[i] == -1)
        {
            break;
        }
    }
    if (pos == -1)
    {
        cout << "number not in array" << endl;
        return -1;
    }
    else
    {
        for (int i = pos; i < size-1; i++)
        {
            Array[i] = Array[i+1];
        }
        Array[--size] = -1;
        return num;
    }
}

int ArrayDB::get(int Num){
    int pos = -1, num;
    for (int i = 0; i < size; i++)
    {
        if (Array[i] == Num)
        {
            num = Array[i];
            pos = i;
            break;
        }
        else if (Array[i] == -1)
        {
            break;
        }
    }
    if (pos == -1)
    {
        cout << "number not in array" << endl;
        return -1;
    }
    else
    {
        return num;
    }
}

void ArrayDB::set(int Num){
    int pos = -1, num;
    for (int i = 0; i < size; i++)
    {
        if (Array[i] == Num)
        {
            num = Array[i];
            pos = i;
            break;
        }
        else if (Array[i] == -1)
        {
            break;
        }
    }
    if (pos == -1)
    {
        cout << "number not in array" << endl;
    }
    else
    {
        Array[pos] = Array[pos];
    }
}