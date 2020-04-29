#include "StackDB.h"

StackDB::StackDB(){
    top = 0;
}

bool StackDB::push(int Num){
    if (top < MAX)
    {
        stackarray[++top] = Num;
        return true;
    }
    else
    {
        cout << "stack overflow" << endl;
        return false;
    }
}

int StackDB::pop(){
    if (isEmpty())
    {
        cout << "stack underflow" << endl;
        return -1;
    }
    else
    {
        return stackarray[top--];
    }
}

bool StackDB::isEmpty(){
    return (top < 0); 
}