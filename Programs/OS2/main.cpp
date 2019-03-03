#include <iostream>
#include <fstream>
#include <vector>
#include "selection.h"
#include "timsort.h"
#include <fstream> 
#include <chrono> 
using namespace std;
//"t1.txt", "t3.txt","t4.txt", "t5.txt","t6.txt", "t2.txt","t7.txt"
int main()
{
    vector<string> testCases = {"t1.txt", "t2.txt","t3.txt","t4.txt","t5.txt","t6.txt","t7.txt","t8.txt","t9.txt","t10.txt"};
    vector<int> testCase;
    ifstream  fileIN;
    ofstream fileOUT;
    fileOUT.open("output.csv");
    chrono::time_point<std::chrono::system_clock> start, end; 
    chrono::duration<double> elapsed_seconds;
    fileOUT << "TimSort" << endl;
    for (auto i : testCases)
    {
        testCase.clear();
        string curLine;
        fileIN.open(i);
        while( fileIN >> curLine)
        {
            testCase.push_back(stoi(curLine));
        }
        int n = testCase.size(); 
        start = chrono::system_clock::now(); 
        timSort(testCase, n); 
        end = chrono::system_clock::now();
        elapsed_seconds = end - start;
        fileOUT << n << ',' << elapsed_seconds.count() << endl;
        fileIN.close();
    }
    fileOUT << endl << "SelectionSort" << endl;
    for (auto i : testCases)
    {
        testCase.clear();
        string curLine;
        fileIN.open(i);
        while( fileIN >> curLine)
        {
            testCase.push_back(stoi(curLine));
        }
        int n = testCase.size(); 
        start = chrono::system_clock::now(); 
        selectionSort(testCase, n); 
        end = chrono::system_clock::now();
        elapsed_seconds = end - start;
        fileOUT << n << ',' << elapsed_seconds.count() << endl;
        fileIN.close();
    }
    return 0; 
}