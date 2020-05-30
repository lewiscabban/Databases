#ifndef BSTDB_H
#define BSTDB_H

#include <bits/stdc++.h> 

using namespace std;

struct Leaf
{
    int value;
    Leaf* left;
    Leaf* right;
};


class BSTDB
{
    private:
        Leaf* root;
    public:
        //constructor
        BSTDB();
        void insert(int Num);
        void addLeaf(int Num, Leaf* leaf);
        void remove(int Num);
        void delLeaf(int Num, Leaf* leaf);
        int get(int Num);
        void set(int Num);
        Leaf* getRoot();
        void inOrder(Leaf* leaf);
};

#endif