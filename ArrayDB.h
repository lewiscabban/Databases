#ifndef ARRAYDB_H
#define ARRAYDB_H

#include <bits/stdc++.h> 

using namespace std;

#define MAX2 10

class ArrayDB
{
    private:
        int Array[MAX2];
        int size;
    public:
        //constructor
        ArrayDB();
        bool push(int Num);
        int pop(int Num);
};

#endif