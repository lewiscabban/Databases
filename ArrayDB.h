#ifndef ARRAYDB_H
#define ARRAYDB_H

#include <bits/stdc++.h> 

using namespace std;

#define MAX2 100000

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
        int get(int Num);
        void set(int Num);
};

#endif