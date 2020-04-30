#include "StackDB.h"
#include "QueueDB.h"
#include "LinkedListDB.h"
#include "ArrayDB.h"
#include <iostream>

#define ARRSIZE 5

int main(int argc, char const *argv[])
{
    //initialise all the classes
    ArrayDB stack;
    int input[ARRSIZE] = {1,2,3,4,5};
    //initialise martix with rows = number of databases and cols = number of tests, this will be used to store the test results

    //read a test from a .txt file and run tests on all the databases and store results in the matrix
    for (int i = 0; i < ARRSIZE; i++)
    {
        stack.push(input[i]);
    }

    for (int i = 0; i < ARRSIZE; i++)
    {
        cout << stack.pop(input[i]) << endl;
    }
    
    //repeat this for all tests

    //output the final results
    //identify bet performing databases for each method

    return 0;
}
