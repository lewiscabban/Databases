#include "StackDB.h"
#include "QueueDB.h"
#include "LinkedListDB.h"
#include "ArrayDB.h"
#include "BSTDB.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>

#define ARRSIZE 100000

using namespace std;

int main(int argc, char const *argv[])
{
    //initialise classes
    StackDB stack;
    QueueDB queue;
    LinkedListDB ll;
    ArrayDB arr;
    BSTDB bst;
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

    ofstream outfile;/*
    outfile.open("array_data_100000.csv");
    outfile << "push,get,set,pop,assend_push,assend_get,assend_set,assend_pop,desend_push,desend_get,desend_set,desend_pop" << endl;

    for (int j = 0; j < 10; j++)
    {
        auto t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 100000; i++)
        {
            arr.push(input_100000.at(i));
        }
        auto t2 = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        auto t3 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 100000; i++)
        {
            arr.pop(input_100000.at(i));
        }
        auto t4 = chrono::high_resolution_clock::now();

        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 100000; i++)
        {
            arr.push(input_100000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();

        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t3 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 100000; i++)
        {
            arr.pop(input_100000.at(i));
        }
        t4 = chrono::high_resolution_clock::now();

        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";


        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 100000; i++)
        {
            arr.push(input_100000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();

        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t3 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 100000; i++)
        {
            arr.pop(input_100000.at(i));
        }
        t4 = chrono::high_resolution_clock::now();

        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << endl;
    }

    outfile.close();

    outfile.open("array_data_50000.csv");
    outfile << "push,get,set,pop,assend_push,assend_get,assend_set,assend_pop,desend_push,desend_get,desend_set,desend_pop" << endl;

    for (int j = 0; j < 10; j++)
    {
        auto t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 50000; i++)
        {
            arr.push(input_50000.at(i));
        }
        auto t2 = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        auto t3 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 50000; i++)
        {
            arr.pop(input_50000.at(i));
        }
        auto t4 = chrono::high_resolution_clock::now();

        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 50000; i++)
        {
            arr.push(input_50000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();

        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t3 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 50000; i++)
        {
            arr.pop(input_50000.at(i));
        }
        t4 = chrono::high_resolution_clock::now();

        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";


        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 50000; i++)
        {
            arr.push(input_50000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();

        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t3 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 50000; i++)
        {
            arr.pop(input_50000.at(i));
        }
        t4 = chrono::high_resolution_clock::now();

        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << endl;
    }

    outfile.close();
    */
    outfile.open("array_data_10000.csv");
    outfile << "push,get,set,pop,assend_push,assend_get,assend_set,assend_pop,desend_push,desend_get,desend_set,desend_pop" << endl;

    for (int j = 0; j < 20; j++)
    {
        random_shuffle(input_10000.begin(),input_10000.end());
        //push,get,set,pop for random array
        auto t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; i++)
        {
            arr.push(input_10000.at(i));
        }
        auto t2 = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        int temp;
        for (int i = 0; i < 10000; i++)
        {
            temp = arr.get(input_10000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 10000; i++)
        {
            arr.set(input_10000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; i++)
        {
            arr.pop(input_10000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        //push,get,set,pop for assending array
        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; i++)
        {
            arr.push(assend_10000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 10000; i++)
        {
            temp = arr.get(assend_10000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 10000; i++)
        {
            arr.set(assend_10000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; i++)
        {
            arr.pop(assend_10000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        //push,get,set,pop for desending array
        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; i++)
        {
            arr.push(desend_10000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 10000; i++)
        {
            temp = arr.get(desend_10000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 10000; i++)
        {
            arr.set(desend_10000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; i++)
        {
            arr.pop(desend_10000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << endl;
    }

    outfile.close();
/*
    outfile.open("array_data_5000.csv");
    outfile << "push,get,set,pop,assend_push,assend_get,assend_set,assend_pop,desend_push,desend_get,desend_set,desend_pop" << endl;

    for (int j = 0; j < 20; j++)
    {
        //push,get,set,pop for random array
        auto t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 5000; i++)
        {
            arr.push(input_5000.at(i));
        }
        auto t2 = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        int temp;
        for (int i = 0; i < 5000; i++)
        {
            temp = arr.get(input_5000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 5000; i++)
        {
            arr.set(input_5000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 5000; i++)
        {
            arr.pop(input_5000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        //push,get,set,pop for assending array
        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 5000; i++)
        {
            arr.push(assend_5000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 5000; i++)
        {
            temp = arr.get(assend_5000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 5000; i++)
        {
            arr.set(assend_5000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 5000; i++)
        {
            arr.pop(assend_5000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        //push,get,set,pop for desending array
        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 5000; i++)
        {
            arr.push(desend_5000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 5000; i++)
        {
            temp = arr.get(desend_5000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 5000; i++)
        {
            arr.set(desend_5000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 5000; i++)
        {
            arr.pop(desend_5000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << endl;
    }

    outfile.close();

    outfile.open("array_data_1000.csv");
    outfile << "push,get,set,pop,assend_push,assend_get,assend_set,assend_pop,desend_push,desend_get,desend_set,desend_pop" << endl;

    for (int j = 0; j < 20; j++)
    {
        //push,get,set,pop for random array
        auto t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 1000; i++)
        {
            arr.push(input_1000.at(i));
        }
        auto t2 = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        int temp;
        for (int i = 0; i < 1000; i++)
        {
            temp = arr.get(input_1000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 1000; i++)
        {
            arr.set(input_1000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 1000; i++)
        {
            arr.pop(input_1000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        //push,get,set,pop for assending array
        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 1000; i++)
        {
            arr.push(assend_1000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 1000; i++)
        {
            temp = arr.get(assend_1000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 1000; i++)
        {
            arr.set(assend_1000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 1000; i++)
        {
            arr.pop(assend_1000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        //push,get,set,pop for desending array
        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 1000; i++)
        {
            arr.push(desend_1000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 1000; i++)
        {
            temp = arr.get(desend_1000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 1000; i++)
        {
            arr.set(desend_1000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 1000; i++)
        {
            arr.pop(desend_1000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << endl;
    }

    outfile.close();

    outfile.open("array_data_500.csv");
    outfile << "push,get,set,pop,assend_push,assend_get,assend_set,assend_pop,desend_push,desend_get,desend_set,desend_pop" << endl;

    for (int j = 0; j < 20; j++)
    {
        //push,get,set,pop for random array
        auto t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 500; i++)
        {
            arr.push(input_500.at(i));
        }
        auto t2 = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        int temp;
        for (int i = 0; i < 500; i++)
        {
            temp = arr.get(input_500.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 500; i++)
        {
            arr.set(input_500.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 500; i++)
        {
            arr.pop(input_500.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        //push,get,set,pop for assending array
        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 500; i++)
        {
            arr.push(assend_500.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 500; i++)
        {
            temp = arr.get(assend_500.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 500; i++)
        {
            arr.set(assend_500.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 500; i++)
        {
            arr.pop(assend_500.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        //push,get,set,pop for desending array
        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 500; i++)
        {
            arr.push(desend_500.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 500; i++)
        {
            temp = arr.get(desend_500.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 500; i++)
        {
            arr.set(desend_500.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 500; i++)
        {
            arr.pop(desend_500.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << endl;
        
    }

    outfile.close();
*/
    outfile.open("LL_data_10000.csv");
    outfile << "push,get,set,pop,assend_push,assend_get,assend_set,assend_pop,desend_push,desend_get,desend_set,desend_pop" << endl;

    for (int j = 0; j < 20; j++)
    {
        random_shuffle(input_10000.begin(),input_10000.end());
        //push,get,set,pop for random array
        auto t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; i++)
        {
            ll.push(input_10000.at(i));
        }
        auto t2 = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        int temp;
        for (int i = 0; i < 10000; i++)
        {
            temp = ll.get(input_10000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 10000; i++)
        {
            ll.set(input_10000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; i++)
        {
            ll.pop(input_10000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        //push,get,set,pop for assending LL
        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; i++)
        {
            ll.push(assend_10000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 10000; i++)
        {
            temp = ll.get(assend_10000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 10000; i++)
        {
            ll.set(assend_10000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; i++)
        {
            ll.pop(assend_10000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        //push,get,set,pop for desending LL
        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; i++)
        {
            ll.push(desend_10000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 10000; i++)
        {
            temp = ll.get(desend_10000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 10000; i++)
        {
            ll.set(desend_10000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; i++)
        {
            ll.pop(desend_10000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << endl;
    }

    outfile.close();
/*
    outfile.open("LL_data_5000.csv");
    outfile << "push,get,set,pop,assend_push,assend_get,assend_set,assend_pop,desend_push,desend_get,desend_set,desend_pop" << endl;

    for (int j = 0; j < 20; j++)
    {
        //push,get,set,pop for random LL
        auto t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 5000; i++)
        {
            ll.push(input_5000.at(i));
        }
        auto t2 = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        int temp;
        for (int i = 0; i < 5000; i++)
        {
            temp = ll.get(input_5000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 5000; i++)
        {
            ll.set(input_5000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 5000; i++)
        {
            ll.pop(input_5000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        //push,get,set,pop for assending LL
        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 5000; i++)
        {
            ll.push(assend_5000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 5000; i++)
        {
            temp = ll.get(assend_5000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 5000; i++)
        {
            ll.set(assend_5000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 5000; i++)
        {
            ll.pop(assend_5000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        //push,get,set,pop for desending LL
        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 5000; i++)
        {
            ll.push(desend_5000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 5000; i++)
        {
            temp = ll.get(desend_5000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 5000; i++)
        {
            ll.set(desend_5000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 5000; i++)
        {
            ll.pop(desend_5000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << endl;
    }

    outfile.close();

    outfile.open("LL_data_1000.csv");
    outfile << "push,get,set,pop,assend_push,assend_get,assend_set,assend_pop,desend_push,desend_get,desend_set,desend_pop" << endl;

    for (int j = 0; j < 20; j++)
    {
        //push,get,set,pop for random LL
        auto t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 1000; i++)
        {
            ll.push(input_1000.at(i));
        }
        auto t2 = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        int temp;
        for (int i = 0; i < 1000; i++)
        {
            temp = ll.get(input_1000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 1000; i++)
        {
            ll.set(input_1000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 1000; i++)
        {
            ll.pop(input_1000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        //push,get,set,pop for assending LL
        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 1000; i++)
        {
            ll.push(assend_1000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 1000; i++)
        {
            temp = ll.get(assend_1000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 1000; i++)
        {
            ll.set(assend_1000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 1000; i++)
        {
            ll.pop(assend_1000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        //push,get,set,pop for desending LL
        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 1000; i++)
        {
            ll.push(desend_1000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 1000; i++)
        {
            temp = ll.get(desend_1000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 1000; i++)
        {
            ll.set(desend_1000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 1000; i++)
        {
            ll.pop(desend_1000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << endl;
    }

    outfile.close();

    outfile.open("LL_data_500.csv");
    outfile << "push,get,set,pop,assend_push,assend_get,assend_set,assend_pop,desend_push,desend_get,desend_set,desend_pop" << endl;

    for (int j = 0; j < 20; j++)
    {
        //push,get,set,pop for random LL
        auto t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 500; i++)
        {
            ll.push(input_500.at(i));
        }
        auto t2 = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        int temp;
        for (int i = 0; i < 500; i++)
        {
            temp = ll.get(input_500.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 500; i++)
        {
            ll.set(input_500.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 500; i++)
        {
            ll.pop(input_500.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        //push,get,set,pop for assending LL
        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 500; i++)
        {
            ll.push(assend_500.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 500; i++)
        {
            temp = ll.get(assend_500.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 500; i++)
        {
            ll.set(assend_500.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 500; i++)
        {
            ll.pop(assend_500.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        //push,get,set,pop for desending LL
        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 500; i++)
        {
            ll.push(desend_500.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 500; i++)
        {
            temp = ll.get(desend_500.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 500; i++)
        {
            ll.set(desend_500.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 500; i++)
        {
            ll.pop(desend_500.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << endl;
        
    }

    outfile.close();


    outfile.open("bst_data_10000.csv");
    outfile << "push,get,set,pop,assend_push,assend_get,assend_set,assend_pop,desend_push,desend_get,desend_set,desend_pop" << endl;

    for (int j = 0; j < 20; j++)
    {
        //push,get,set,pop for random array
        auto t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; i++)
        {
            bst.insert(input_10000.at(i));
        }
        auto t2 = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        int temp;
        for (int i = 0; i < 10000; i++)
        {
            temp = bst.get(input_10000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 10000; i++)
        {
            bst.set(input_10000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; i++)
        {
            bst.remove(input_10000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        //push,get,set,pop for assending bst
        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; i++)
        {
            bst.insert(assend_10000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 10000; i++)
        {
            temp = bst.get(assend_10000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 10000; i++)
        {
            bst.set(assend_10000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; i++)
        {
            bst.remove(assend_10000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        //push,get,set,pop for desending bst
        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; i++)
        {
            bst.insert(desend_10000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 10000; i++)
        {
            temp = bst.get(desend_10000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 10000; i++)
        {
            bst.set(desend_10000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; i++)
        {
            bst.remove(desend_10000.at(i));
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
            bst.insert(input_5000.at(i));
        }
        auto t2 = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        int temp;
        for (int i = 0; i < 5000; i++)
        {
            temp = bst.get(input_5000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 5000; i++)
        {
            bst.set(input_5000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 5000; i++)
        {
            bst.remove(input_5000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        //push,get,set,pop for assending bst
        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 5000; i++)
        {
            bst.insert(assend_5000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 5000; i++)
        {
            temp = bst.get(assend_5000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 5000; i++)
        {
            bst.set(assend_5000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 5000; i++)
        {
            bst.remove(assend_5000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        //push,get,set,pop for desending bst
        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 5000; i++)
        {
            bst.insert(desend_5000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 5000; i++)
        {
            temp = bst.get(desend_5000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 5000; i++)
        {
            bst.set(desend_5000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 5000; i++)
        {
            bst.remove(desend_5000.at(i));
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
            bst.insert(input_1000.at(i));
        }
        auto t2 = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        int temp;
        for (int i = 0; i < 1000; i++)
        {
            temp = bst.get(input_1000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 1000; i++)
        {
            bst.set(input_1000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 1000; i++)
        {
            bst.remove(input_1000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        //push,get,set,pop for assending bst
        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 1000; i++)
        {
            bst.insert(assend_1000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 1000; i++)
        {
            temp = bst.get(assend_1000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 1000; i++)
        {
            bst.set(assend_1000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 1000; i++)
        {
            bst.remove(assend_1000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        //push,get,set,pop for desending bst
        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 1000; i++)
        {
            bst.insert(desend_1000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 1000; i++)
        {
            temp = bst.get(desend_1000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 1000; i++)
        {
            bst.set(desend_1000.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 1000; i++)
        {
            bst.remove(desend_1000.at(i));
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
            bst.insert(input_500.at(i));
        }
        auto t2 = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        int temp;
        for (int i = 0; i < 500; i++)
        {
            temp = bst.get(input_500.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 500; i++)
        {
            bst.set(input_500.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 500; i++)
        {
            bst.remove(input_500.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        //push,get,set,pop for assending bst
        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 500; i++)
        {
            bst.insert(assend_500.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 500; i++)
        {
            temp = bst.get(assend_500.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 500; i++)
        {
            bst.set(assend_500.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 500; i++)
        {
            bst.remove(assend_500.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        //push,get,set,pop for desending bst
        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 500; i++)
        {
            bst.insert(desend_500.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 500; i++)
        {
            temp = bst.get(desend_500.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        temp;
        for (int i = 0; i < 500; i++)
        {
            bst.set(desend_500.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << ",";

        t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 500; i++)
        {
            bst.remove(desend_500.at(i));
        }
        t2 = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        outfile << duration << endl;
        
    }

    outfile.close();
    /***** tree search
    tree.insert(3);
    tree.insert(2);
    tree.insert(1);

    tree.inOrder(tree.getRoot());

    //tree.remove(3);
    //tree.remove(2);
    tree.remove(1);

    tree.inOrder(tree.getRoot());

    return 0;
    */
}

