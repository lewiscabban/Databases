#include "QueueDB.h"

QueueDB::QueueDB(){
    top = 0;
    bottom = 0;
}

bool QueueDB::push(int Num){
    if (!isFull())
    {
        if (top == MAX1)
        {
            top = 0;
        }
        else
        {
            top++;
        }
        
        queuearray[top] = Num;
        
        return true;
    }
    else
    {
        cout << "stack overflow" << endl;
        return false;
    }
}

int QueueDB::pop(){
    if (isEmpty())
    {
        cout << "stack underflow" << endl;
        return -1;
    }
    else
    {
        if (bottom == MAX1)
        {
            bottom = 0;
        }
        else
        {
            bottom++;
        }
        
        return queuearray[bottom];
    }
}

bool QueueDB::isEmpty(){
    return (top == bottom); 
}
bool QueueDB::isFull(){
    return ((top - bottom) == -1 || (top - bottom) == MAX1); 
}