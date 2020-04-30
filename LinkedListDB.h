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
        int find(int Num);
};

#endif