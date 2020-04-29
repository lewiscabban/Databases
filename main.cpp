#include "StackDB.h"
#include "QueueDB.h"
#include <iostream>

#define ARRSIZE 5

int main(int argc, char const *argv[])
{
    //initialise all the classes
    QueueDB stack;
    int input[ARRSIZE] = {1,2,3,4,5};
    //initialise martix with rows = number of databases and cols = number of tests, this will be used to store the test results

    //read a test from a .txt file and run tests on all the databases and store results in the matrix
    for (int i = 0; i < ARRSIZE; i++)
    {
        if(stack.push(input[i]) == false)
        {
            cout << "exiting due to error!" << endl;
        }
    }

    for (int i = 0; i < ARRSIZE; i++)
    {
        cout << stack.pop() << endl;
    }
    
    //repeat this for all tests

    //output the final results
    //identify bet performing databases for each method

    return 0;
}
