// C++ program to implement optimized delete in avl. 
#include <bits/stdc++.h> 
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>

#define ARRSIZE 100000

using namespace std; 
  
// An AVL tree node  
class Node  
{  
    public: 
    int key;  
    Node *left;  
    Node *right;  
    int height;  
};  
  
// A utility function to get maximum 
// of two integers  
int max(int a, int b);  
  
// A utility function to get height  
// of the tree  
int height(Node *N)  
{  
    if (N == NULL)  
        return 0;  
    return N->height;  
}  
  
// A utility function to get maximum 
// of two integers  
int max(int a, int b)  
{  
    return (a > b)? a : b;  
}  
  
/* Helper function that allocates a  
   new node with the given key and  
   NULL left and right pointers. */
Node* newNode(int key)  
{  
    Node* node = new Node(); 
    node->key = key;  
    node->left = NULL;  
    node->right = NULL;  
    node->height = 1; // new node is initially 
                      // added at leaf  
    return(node);  
}  
  
// A utility function to right 
// rotate subtree rooted with y  
// See the diagram given above.  
Node *rightRotate(Node *y)  
{  
    Node *x = y->left;  
    Node *T2 = x->right;  
  
    // Perform rotation  
    x->right = y;  
    y->left = T2;  
  
    // Update heights  
    y->height = max(height(y->left),  
                    height(y->right)) + 1;  
    x->height = max(height(x->left),  
                    height(x->right)) + 1;  
  
    // Return new root  
    return x;  
}  
  
// A utility function to left  
// rotate subtree rooted with x  
// See the diagram given above.  
Node *leftRotate(Node *x)  
{  
    Node *y = x->right;  
    Node *T2 = y->left;  
  
    // Perform rotation  
    y->left = x;  
    x->right = T2;  
  
    // Update heights  
    x->height = max(height(x->left),  
                    height(x->right)) + 1;  
    y->height = max(height(y->left),  
                    height(y->right)) + 1;  
  
    // Return new root  
    return y;  
}  
  
// Get Balance factor of node N  
int getBalance(Node *N)  
{  
    if (N == NULL)  
        return 0;  
    return height(N->left) -  
           height(N->right);  
}  
  
Node* insert(Node* node, int key)  
{  
    /* 1. Perform the normal BST rotation */
    if (node == NULL)  
        return(newNode(key));  
  
    if (key < node->key)  
        node->left = insert(node->left, key);  
    else if (key > node->key)  
        node->right = insert(node->right, key);  
    else // Equal keys not allowed  
        return node;  
  
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left),  
                           height(node->right));  
  
    /* 3. Get the balance factor of this  
        ancestor node to check whether  
        this node became unbalanced */
    int balance = getBalance(node);  
  
    // If this node becomes unbalanced, 
    // then there are 4 cases  
  
    // Left Left Case  
    if (balance > 1 && key < node->left->key)  
        return rightRotate(node);  
  
    // Right Right Case  
    if (balance < -1 && key > node->right->key)  
        return leftRotate(node);  
  
    // Left Right Case  
    if (balance > 1 && key > node->left->key)  
    {  
        node->left = leftRotate(node->left);  
        return rightRotate(node);  
    }  
  
    // Right Left Case  
    if (balance < -1 && key < node->right->key)  
    {  
        node->right = rightRotate(node->right);  
        return leftRotate(node);  
    }  
  
    /* return the (unchanged) node pointer */
    return node;  
}  
  
/* Given a non-empty binary search tree,  
return the node with minimum key value  
found in that tree. Note that the entire  
tree does not need to be searched. */
Node * minValueNode(Node* node)  
{  
    Node* current = node;  
  
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)  
        current = current->left;  
  
    return current;  
}  
  
// Recursive function to delete a node  
// with given key from subtree with  
// given root. It returns root of the  
// modified subtree.  
Node* deleteNode(Node* root, int key)  
{  
      
    // STEP 1: PERFORM STANDARD BST DELETE  
    if (root == NULL)  
        return root;  
  
    // If the key to be deleted is smaller  
    // than the root's key, then it lies 
    // in left subtree  
    if ( key < root->key )  
        root->left = deleteNode(root->left, key);  
  
    // If the key to be deleted is greater  
    // than the root's key, then it lies  
    // in right subtree  
    else if( key > root->key )  
        root->right = deleteNode(root->right, key);  
  
    // if key is same as root's key, then  
    // This is the node to be deleted  
    else
    {  
        // node with only one child or no child  
        if( (root->left == NULL) || 
            (root->right == NULL) )  
        {  
            Node *temp = root->left ?  
                         root->left :  
                         root->right;  
  
            // No child case  
            if (temp == NULL)  
            {  
                temp = root;  
                root = NULL;  
            }  
            else // One child case  
            *root = *temp; // Copy the contents of  
                           // the non-empty child  
            free(temp);  
        }  
        else
        {  
            // node with two children: Get the inorder  
            // successor (smallest in the right subtree)  
            Node* temp = minValueNode(root->right);  
  
            // Copy the inorder successor's  
            // data to this node  
            root->key = temp->key;  
  
            // Delete the inorder successor  
            root->right = deleteNode(root->right,  
                                     temp->key);  
        }  
    }  
  
    // If the tree had only one node 
    // then return  
    if (root == NULL)  
    return root;  
  
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE  
    root->height = 1 + max(height(root->left),  
                           height(root->right));  
  
    // STEP 3: GET THE BALANCE FACTOR OF  
    // THIS NODE (to check whether this  
    // node became unbalanced)  
    int balance = getBalance(root);  
  
    // If this node becomes unbalanced,  
    // then there are 4 cases  
  
    // Left Left Case  
    if (balance > 1 &&  
        getBalance(root->left) >= 0)  
        return rightRotate(root);  
  
    // Left Right Case  
    if (balance > 1 &&  
        getBalance(root->left) < 0)  
    {  
        root->left = leftRotate(root->left);  
        return rightRotate(root);  
    }  
  
    // Right Right Case  
    if (balance < -1 &&  
        getBalance(root->right) <= 0)  
        return leftRotate(root);  
  
    // Right Left Case  
    if (balance < -1 &&  
        getBalance(root->right) > 0)  
    {  
        root->right = rightRotate(root->right);  
        return leftRotate(root);  
    }  
  
    return root;  
}  
  
// A utility function to print preorder  
// traversal of the tree.  
// The function also prints height  
// of every node  
void preOrder(Node *root)  
{  
    if(root != NULL)  
    {  
        cout << root->key << " ";  
        preOrder(root->left);  
        preOrder(root->right);  
    }  
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
    outfile.open("avl_data_10000.csv");
    outfile << "push,get,set,pop,assend_push,assend_get,assend_set,assend_pop,desend_push,desend_get,desend_set,desend_pop" << endl;

    for (int j = 0; j < 20; j++)
    {
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

    outfile.open("avl_data_5000.csv");
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

    outfile.open("avl_data_1000.csv");
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

    outfile.open("avl_data_500.csv");
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