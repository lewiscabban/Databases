#include "BSTDB.h"

//initialise the class with an empty tree
BSTDB::BSTDB(){
    root = NULL;
}

void BSTDB::insert(int Num){
    
    if (root == NULL)
    {
        //tree is empty initialise the leaf as the root
        Leaf* newleaf = new Leaf();
        newleaf->value = Num;
        newleaf->right = NULL;
        newleaf->left = NULL;
        root = newleaf;
    }
    else
    {
        // find a position in the tree to insert Num
        addLeaf(Num,root);
    }
}

//recursion to go down a tree until a position to insert a new leaf is identified
void BSTDB::addLeaf(int Num, Leaf* leaf){
    if (Num < leaf->value)
    {
        //search left subtree if Num is smaller than the current leaf value
        if (leaf->left == NULL)
        {
            //create new leaf and connect it to the tree
            Leaf* newleaf = new Leaf();
            newleaf->value = Num;
            newleaf->right = NULL;
            newleaf->left = NULL;
            leaf->left = newleaf;
        }
        else
        {
            //recursively search the left sub tree for a free leaf
            addLeaf(Num,leaf->left);
        }
    }
    else
    {
        //search right subtree if Num is larger than or equal to the current leaf value
        if (leaf->right == NULL)
        {
            //create new leaf and connect it to the tree
            Leaf* newleaf = new Leaf();
            newleaf->value = Num;
            newleaf->right = NULL;
            newleaf->left = NULL;
            leaf->right = newleaf;
        }
        else
        {
            //recursively search the right sub tree for a free leaf
            addLeaf(Num,leaf->right);
        }
    }
}

void BSTDB::remove(int Num){
    if (root == NULL)
    {
        //if the tree is empty nothing can be deleted
        cout << "stack underflow" << endl;
        return;
    }
    else if (root->value == Num)
    {
        //delete root leaf
        Leaf* temp = root->left;
        if (root->left == NULL)
        {
            //move up right subtree
            temp = root->right;
            delete root;
            root = temp;
        }
        else if (temp->right == NULL)
        {
            //move up left subtree
            temp->right = root->right;
            delete root;
            root = temp;
        }
        else
        {
            //replace root with larget value in left subtree
            Leaf* last = NULL;
            while (temp->right != NULL)
            {
                last = temp;
                temp = temp->right;
            }
            last->right = temp->left;
            temp->left = root->left;
            temp->right = root->right;
            delete root;
            root = temp;
        }
    }
    else
    {
        delLeaf(Num,root);
    }
}

//recursion to go down a tree until a position to insert a new leaf is identified
void BSTDB::delLeaf(int Num, Leaf* leaf){
    if (Num < leaf->value)
    {
        //search left subtree if Num is smaller than the current leaf value
        if (leaf->left == NULL)
        {
            //create new leaf and connect it to the tree
            cout << "number not found" << endl;
            return;
        }
        else
        {
            //recursively search the left sub tree for a free leaf
            Leaf* next = leaf->left;
            if (next->value == Num)
            {
                //delete leaf
                Leaf* temp = next->left;
                if (next->left == NULL)
                {
                    //move up right subtree
                    temp = next->right;
                    delete next;
                    leaf->left = temp;
                }
                else if (temp->right == NULL)
                {
                    //move temp up
                    leaf->left = temp;
                    temp->right = next->right;
                    delete next;
                }
                else
                {
                    //replace root with larget value in left subtree
                    Leaf* last = NULL;
                    while (temp->right != NULL)
                    {
                        last = temp;
                        temp = temp->right;
                    }
                    last->right = temp->left;
                    temp->left = next->left;
                    temp->right = next->right;
                    leaf->left = temp;
                    delete next;
                }
            }
            else
            {
                //recursively search left sub tree
                delLeaf(Num,leaf->left);
            }
        }
    }
    else
    {
        //search left subtree if Num is smaller than the current leaf value
        if (leaf->right == NULL)
        {
            //create new leaf and connect it to the tree
            cout << "number not found" << endl;
            return;
        }
        else
        {
            //recursively search the left sub tree for a free leaf
            Leaf* next = leaf->right;
            if (next->value == Num)
            {
                //delete leaf
                Leaf* temp = next->left;
                if (next->left == NULL)
                {
                    //move up right subtree
                    temp = next->right;
                    delete next;
                    leaf->left = temp;
                }
                else if (temp->right == NULL)
                {
                    //move temp up
                    leaf->right = temp;
                    temp->right = next->right;
                    delete next;
                }
                else
                {
                    //replace root with larget value in left subtree
                    Leaf* last = NULL;
                    while (temp->right != NULL)
                    {
                        last = temp;
                        temp = temp->right;
                    }
                    last->right = temp->left;
                    temp->left = next->left;
                    temp->right = next->right;
                    leaf->right = temp;
                    delete next;
                }
            }
            else
            {
                //recursively search right sub tree
                delLeaf(Num,leaf->right);
            }
        }
    }
}

//search the tree for a number
int BSTDB::get(int Num){
    Leaf* temp = root;
    while (temp != NULL)
    {
        //loop through tree until end og branch or Num is found
        if (temp->value == Num)
        {
            break;
        }
        else if (Num < temp->value)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    if (temp == NULL)
    {
        //number not in tree
        cout << "number not in database" << endl;
        return -1;
    }
    else
    {
        //number found return value
        return temp->value;
    }
}

//search the tree for a number and replace it 
void BSTDB::set(int Num){
    Leaf* temp = root;
    while (temp != NULL)
    {
        //loop through tree until end og branch or Num is found
        if (temp->value == Num)
        {
            break;
        }
        else if (Num < temp->value)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    if (temp == NULL)
    {
        //number not in tree
        cout << "number not in database" << endl;
    }
    else
    {
        //number found return value
        temp->value = temp->value;
    }
}

Leaf* BSTDB::getRoot()
{
    return root;
}

void BSTDB::inOrder(Leaf* leaf)
{
    if (leaf == NULL)
    {
        cout << "tree empty!" << endl;
        return;
    }
    
    if (leaf->left != NULL)
    {
        inOrder(leaf->left);
    }
    cout << leaf->value << endl;
    if (leaf->right != NULL)
    {
        inOrder(leaf->right);
    }
}