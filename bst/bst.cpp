// C++ program to implement optimized delete in BST. 
#include <bits/stdc++.h> 
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>

#define ARRSIZE 100000

using namespace std; 
  
struct Node { 
    int key; 
    struct Node *left, *right; 
}; 
  
// A utility function to create a new BST node 
Node* newNode(int item) 
{ 
    Node* temp = new Node; 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
// A utility function to do inorder traversal of BST 
void inorder(Node* root) 
{ 
    if (root != NULL) { 
        inorder(root->left); 
        printf("%d ", root->key); 
        inorder(root->right); 
    } 
} 
  
/* A utility function to insert a new node with given key in BST */
Node* insert(Node* node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) 
        return newNode(key); 
  
    /* Otherwise, recur down the tree */
    if (key < node->key) 
        node->left = insert(node->left, key); 
    else
        node->right = insert(node->right, key); 
  
    /* return the (unchanged) node pointer */
    return node; 
}

/* A utility function to insert a new node with given key in BST */
void access(Node* node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node->key == key) 
    {
        node->key = key;
        return;
    } 
  
    /* Otherwise, recur down the tree */
    if (key < node->key) 
        access(node->left, key); 
    else
        access(node->right, key); 
}

/* A utility function to insert a new node with given key in BST */
int get(Node* node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node->key == key) 
    {
        return key;
    } 
  
    /* Otherwise, recur down the tree */
    if (key < node->key) 
        return get(node->left, key); 
    else
        return get(node->right, key); 

    return -1;
}
  
/* Given a binary search tree and a key, this function deletes the key 
   and returns the new root */
Node* deleteNode(Node* root, int k) 
{ 
    // Base case 
    if (root == NULL) 
        return root; 
  
    // Recursive calls for ancestors of 
    // node to be deleted 
    if (root->key > k) { 
        root->left = deleteNode(root->left, k); 
        return root; 
    } 
    else if (root->key < k) { 
        root->right = deleteNode(root->right, k); 
        return root; 
    } 
  
    // We reach here when root is the node 
    // to be deleted. 
  
    // If one of the children is empty 
    if (root->left == NULL) { 
        Node* temp = root->right; 
        delete root; 
        return temp; 
    } 
    else if (root->right == NULL) { 
        Node* temp = root->left; 
        delete root; 
        return temp; 
    } 
  
    // If both children exist 
    else { 
  
        Node* succParent = root; 
          
        // Find successor 
        Node *succ = root->right; 
        while (succ->left != NULL) { 
            succParent = succ; 
            succ = succ->left; 
        } 
  
        // Delete successor.  Since successor 
        // is always left child of its parent 
        // we can safely make successor's right 
        // right child as left of its parent. 
        // If there is no succ, then assign  
        // succ->right to succParent->right 
        if (succParent != root) 
            succParent->left = succ->right; 
        else
            succParent->right = succ->right; 
  
        // Copy Successor Data to root 
        root->key = succ->key; 
  
        // Delete Successor and return root 
        delete succ;          
        return root; 
    } 
} 



int main(int argc, char const *argv[])
{
    //initialise classes
    vector<int> input_100000,input_50000,input_10000,input_5000,input_1000,input_500;
    vector<int> assend_100000,assend_50000,assend_10000,assend_5000,assend_1000,assend_500;
    vector<int> desend_100000,desend_50000,desend_10000,desend_5000,desend_1000,desend_500;
    /*
    vector<int> DB_01_100000,DB_02_100000,DB_03_100000,DB_04_100000,DB_0500_100000,DB_06_100000,DB_07_100000,DB_08_100000,DB_09_100000,DB_1000_100000,DB_11_100000,DB_12_100000,DB_13_100000,DB_14_100000,DB_1500_100000,DB_16_100000,DB_17_100000,DB_18_100000,DB_19_100000,DB_20_100000,assend_100000,desend_100000;
    vector<int> DB_01_50000,DB_02_50000,DB_03_50000,DB_04_50000,DB_0500_50000,DB_06_50000,DB_07_50000,DB_08_50000,DB_09_50000,DB_1000_50000,DB_11_50000,DB_12_50000,DB_13_50000,DB_14_50000,DB_1500_50000,DB_16_50000,DB_17_50000,DB_18_50000,DB_19_50000,DB_20_50000,assend_50000,desend_50000;
    vector<int> DB_01_10000,DB_02_10000,DB_03_10000,DB_04_10000,DB_0500_10000,DB_06_10000,DB_07_10000,DB_08_10000,DB_09_10000,DB_1000_10000,DB_11_10000,DB_12_10000,DB_13_10000,DB_14_10000,DB_1500_10000,DB_16_10000,DB_17_10000,DB_18_10000,DB_19_10000,DB_20_10000,assend_10000,desend_10000;
    vector<int> DB_01_5000,DB_02_5000,DB_03_5000,DB_04_5000,DB_0500_5000,DB_06_5000,DB_07_5000,DB_08_5000,DB_09_5000,DB_1000_5000,DB_11_5000,DB_12_5000,DB_13_5000,DB_14_5000,DB_1500_5000,DB_16_5000,DB_17_5000,DB_18_5000,DB_19_5000,DB_20_5000,assend_5000,desend_5000;
    vector<int> DB_01_1000,DB_02_1000,DB_03_1000,DB_04_1000,DB_0500_1000,DB_06_1000,DB_07_1000,DB_08_1000,DB_09_1000,DB_1000_1000,DB_11_1000,DB_12_1000,DB_13_1000,DB_14_1000,DB_1500_1000,DB_16_1000,DB_17_1000,DB_18_1000,DB_19_1000,DB_20_1000,assend_1000,desend_1000;
    vector<int> DB_01_500,DB_02_500,DB_03_500,DB_04_500,DB_0500_500,DB_06_500,DB_07_500,DB_08_500,DB_09_500,DB_1000_500,DB_11_500,DB_12_500,DB_13_500,DB_14_500,DB_1500_500,DB_16_500,DB_17_500,DB_18_500,DB_19_500,DB_20_500,assend_500,desend_500;
    */
    srand(unsigned(std::time(0)));

    for (int i = 1; i <= 100000; i++)
    {
        input_100000.push_back(i);
        assend_100000.push_back(i);
        desend_100000.push_back(100001-i);
    }
    for (int i = 1; i <= 50000; i++)
    {
        input_50000.push_back(i);
        assend_50000.push_back(i);
        desend_50000.push_back(50001-i);
    }
    for (int i = 1; i <= 10000; i++)
    {
        input_10000.push_back(i);
        assend_10000.push_back(i);
        desend_10000.push_back(10001-i);
    }
    for (int i = 1; i <= 5000; i++)
    {
        input_5000.push_back(i);
        assend_5000.push_back(i);
        desend_5000.push_back(5001-i);
    }
    for (int i = 1; i <= 1000; i++)
    {
        input_1000.push_back(i);
        assend_1000.push_back(i);
        desend_1000.push_back(1001-i);
    }
    for (int i = 1; i <= 500; i++)
    {
        input_500.push_back(i);
        assend_500.push_back(i);
        desend_500.push_back(501-i);
    }
    
    random_shuffle(input_100000.begin(),input_100000.end());
    random_shuffle(input_50000.begin(),input_50000.end());
    random_shuffle(input_10000.begin(),input_10000.end());
    random_shuffle(input_5000.begin(),input_5000.end());
    random_shuffle(input_1000.begin(),input_1000.end());
    random_shuffle(input_500.begin(),input_500.end());

    Node* root = NULL; 
    int temp; 
    ofstream outfile;
    outfile.open("bst_data_10000.csv");
    outfile << "push,get,set,pop,assend_push,assend_get,assend_set,assend_pop,desend_push,desend_get,desend_set,desend_pop" << endl;

    for (int j = 0; j < 20; j++)
    {
        random_shuffle(input_10000.begin(),input_10000.end());
        //push,get,set,pop for random array
        auto t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; i++)
        {
            root = insert(root,input_10000.at(i));
        }
        auto t2 = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        int temp;
        for (int i = 0; i < 10000; i++)
        {
            temp = get(root,input_10000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 10000; i++)
        {
            access(root,input_10000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; i++)
        {
            root = deleteNode(root,input_10000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        //push,get,set,pop for assending bst
        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; i++)
        {
            root = insert(root,assend_10000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 10000; i++)
        {
            temp = get(root,assend_10000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 10000; i++)
        {
            access(root,assend_10000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; i++)
        {
            root = deleteNode(root,assend_10000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        //push,get,set,pop for desending bst
        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; i++)
        {
            root = insert(root,desend_10000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 10000; i++)
        {
            temp = get(root,desend_10000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 10000; i++)
        {
            access(root,desend_10000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; i++)
        {
            root = deleteNode(root,desend_10000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << endl;
    }

    outfile.close();

    outfile.open("bst_data_5000.csv");
    outfile << "push,get,set,pop,assend_push,assend_get,assend_set,assend_pop,desend_push,desend_get,desend_set,desend_pop" << endl;

    for (int j = 0; j < 20; j++)
    {
        //push,get,set,pop for random bst
        auto t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 5000; i++)
        {
            root = insert(root,input_5000.at(i));
        }
        auto t2 = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        int temp;
        for (int i = 0; i < 5000; i++)
        {
            temp = get(root,input_5000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 5000; i++)
        {
            access(root,input_5000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 5000; i++)
        {
            root = deleteNode(root,input_5000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        //push,get,set,pop for assending bst
        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 5000; i++)
        {
            root = insert(root,assend_5000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 5000; i++)
        {
            temp = get(root,assend_5000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 5000; i++)
        {
            access(root,assend_5000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 5000; i++)
        {
            root = deleteNode(root,assend_5000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        //push,get,set,pop for desending bst
        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 5000; i++)
        {
            root = insert(root,desend_5000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 5000; i++)
        {
            temp = get(root,desend_5000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 5000; i++)
        {
            access(root,desend_5000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 5000; i++)
        {
            root = deleteNode(root,desend_5000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << endl;
    }

    outfile.close();

    outfile.open("bst_data_1000.csv");
    outfile << "push,get,set,pop,assend_push,assend_get,assend_set,assend_pop,desend_push,desend_get,desend_set,desend_pop" << endl;

    for (int j = 0; j < 20; j++)
    {
        //push,get,set,pop for random bst
        auto t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 1000; i++)
        {
            root = insert(root,input_1000.at(i));
        }
        auto t2 = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        int temp;
        for (int i = 0; i < 1000; i++)
        {
            temp = get(root,input_1000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 1000; i++)
        {
            access(root,input_1000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 1000; i++)
        {
            root = deleteNode(root,input_1000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        //push,get,set,pop for assending bst
        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 1000; i++)
        {
            root = insert(root,assend_1000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 1000; i++)
        {
            temp = get(root,assend_1000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 1000; i++)
        {
            access(root,assend_1000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 1000; i++)
        {
            root = deleteNode(root,assend_1000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        //push,get,set,pop for desending bst
        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 1000; i++)
        {
            root = insert(root,desend_1000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 1000; i++)
        {
            temp = get(root,desend_1000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 1000; i++)
        {
            access(root,desend_1000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 1000; i++)
        {
            root = deleteNode(root,desend_1000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << endl;
    }

    outfile.close();

    outfile.open("bst_data_500.csv");
    outfile << "push,get,set,pop,assend_push,assend_get,assend_set,assend_pop,desend_push,desend_get,desend_set,desend_pop" << endl;

    for (int j = 0; j < 20; j++)
    {
        //push,get,set,pop for random bst
        auto t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 500; i++)
        {
            root = insert(root,input_500.at(i));
        }
        auto t2 = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        int temp;
        for (int i = 0; i < 500; i++)
        {
            temp = get(root,input_500.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 500; i++)
        {
            access(root,input_500.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 500; i++)
        {
            root = deleteNode(root,input_500.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        //push,get,set,pop for assending bst
        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 500; i++)
        {
            root = insert(root,assend_500.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 500; i++)
        {
            temp = get(root,assend_500.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 500; i++)
        {
            access(root,assend_500.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 500; i++)
        {
            root = deleteNode(root,assend_500.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        //push,get,set,pop for desending bst
        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 500; i++)
        {
            root = insert(root,desend_500.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 500; i++)
        {
            temp = get(root,desend_500.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 500; i++)
        {
            access(root,desend_500.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 500; i++)
        {
            root = deleteNode(root,desend_500.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << endl;
        
    }

    outfile.close();
}