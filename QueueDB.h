#ifndef QUEUEDB_H
#define QUEUEDB_H

#include <bits/stdc++.h> 

using namespace std;

#define MAX1 4

class QueueDB
{
    private:
        int queuearray[MAX1];
        int top, bottom;
    public:
        //constructor
        QueueDB();
        bool push(int Num);
        int pop();
        bool isEmpty();
        bool isFull();
};

#endif