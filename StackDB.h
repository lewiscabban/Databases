#ifndef STACKDB_H
#define STACKDB_H

#include <bits/stdc++.h> 

using namespace std;

#define MAX 1000

class StackDB
{
    private:
        int stackarray[MAX];
        int top;
    public:
        //constructor
        StackDB();
        bool push(int Num);
        int pop(int Num);
        bool isEmpty();
};

#endif