#ifndef LINKEDLISTDB_H
#define LINKEDLISTDB_H

#include <bits/stdc++.h> 

using namespace std;

struct Node
{
    int value;
    Node* next;
};


class LinkedListDB
{
    private:
        Node* head;
    public:
        //constructor
        LinkedListDB();
        void push(int Num);
        int pop(int Num);
        int get(int Num);
        void set(int Num);
};

#endif