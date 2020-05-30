#include "LinkedListDB.h"

LinkedListDB::LinkedListDB(){
    head = NULL;
}

void LinkedListDB::push(int Num){
    if (head == NULL)
    {
        Node* newnode = new Node();
        newnode->value = Num;
        newnode->next = NULL;
        head = newnode;
        return;
    }
    
    Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node* newnode = new Node();
    newnode->value = Num;
    newnode->next = NULL;
    temp->next = newnode;
}

int LinkedListDB::pop(int Num){
    Node* temp = head;
    Node* last;
    while (temp->next != NULL)
    {
        if (temp->value == Num)
        {
            break;
        }
        
        last = temp;
        temp = temp->next;
    }
    if (temp == head)
    {
        head = temp->next;
        int val = temp->value;
        delete temp;
        return val;
    }
    else if (temp->value == Num)
    {
        last->next = temp->next;
        int val = temp->value;
        delete temp;
        return val;
    }
    else
    {
        cout << "number not in database" << endl;
        return -1;
    }
    
    
}

int LinkedListDB::get(int Num){
    Node* temp = head;
    while (temp != NULL)
    {
        if (temp->value == Num)
        {
            break;
        }
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "number not in database" << endl;
        return -1;
    }
    else
    {
        return temp->value;
    }
}

void LinkedListDB::set(int Num){
    Node* temp = head;
    while (temp != NULL)
    {
        if (temp->value == Num)
        {
            break;
        }
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "number not in database" << endl;
    }
    else
    {
        temp->value = Num;
    }
}