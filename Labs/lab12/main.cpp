#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <vector>
#include <fstream> 
#include <chrono> 
using namespace std;


int shellSort(vector<int> &arr, int n) 
{ 
    for (int gap = n/2; gap > 0; gap /= 2) 
    { 
        for (int i = gap; i < n; i += 1) 
        { 
            int temp = arr[i]; 
            int j;             
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
                arr[j] = arr[j - gap]; 
            arr[j] = temp; 
        } 
    } 
    return 0; 
} 

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

//"t1.txt", "t3.txt","t4.txt", "t5.txt","t6.txt", "t2.txt","t7.txt"
int main()
{
    vector<string> testCases = {"test1.txt", "test2.txt", "test3.txt", "test4.txt", "test5.txt", "test6.txt", "test7.txt", "test8.txt", "test9.txt", "test10.txt", "test11.txt", "test12.txt", "test13.txt", "test14.txt", "test15.txt"};
    vector<int> testCase;
    ifstream  fileIN;
    ofstream fileOUT;
    fileOUT.open("output.csv");
    chrono::time_point<std::chrono::system_clock> start, end; 
    chrono::duration<double> elapsed_seconds;
    fileOUT << "std::sort" << endl;
    int size;
    double average;
    for (auto i : testCases)
    {
        average = 0;
        for(int j = 0; j < 3; j++)
        {
            testCase.clear();
            string curLine;
            fileIN.open(i);
            while( fileIN >> curLine)
            {
                testCase.push_back(stoi(curLine));
            }
            if(j == 0){size = testCase.size();}
            start = chrono::system_clock::now(); 
            sort(testCase.begin(), testCase.end());
            end = chrono::system_clock::now();
            elapsed_seconds = end - start;
            average += elapsed_seconds.count();
        }
        fileOUT << size << ',' << average/3 << endl;
        fileIN.close();
    }
    std::cout << "FINISHED SORT" << endl;
    
    fileOUT << endl << "std::stable_sort" << endl;
    for (auto i : testCases)
    {
        average = 0;
        for(int j = 0; j < 3; j++)
        {
        testCase.clear();
        string curLine;
        fileIN.open(i);
        while( fileIN >> curLine)
        {
            testCase.push_back(stoi(curLine));
        }
        if(j == 0){size = testCase.size();}
        start = chrono::system_clock::now(); 
        stable_sort(testCase.begin(), testCase.end());
        end = chrono::system_clock::now();
        elapsed_seconds = end - start;
         average += elapsed_seconds.count();
        }
        fileOUT << size << ',' << average/3 << endl;
        fileIN.close();
    }
    std::cout << "FINISHED STABLE SORT" << endl;

    fileOUT << endl << "std::heap_sort" << endl;
    for (auto i : testCases)
    {average = 0;
        for(int j = 0; j < 3; j++)
        {
        testCase.clear();
        string curLine;
        fileIN.open(i);
        while( fileIN >> curLine)
        {
            testCase.push_back(stoi(curLine));
        }
        if(j == 0){size = testCase.size();}
        start = chrono::system_clock::now(); 
        sort_heap(testCase.begin(), testCase.end());
        end = chrono::system_clock::now();
        elapsed_seconds = end - start;
         average += elapsed_seconds.count();
        }
        fileOUT << size << ',' << average/3 << endl;
        fileIN.close();
    }
    std::cout << "FINISHED HEAP SORT" << endl;

    fileOUT << endl << "std::qsort" << endl;
    for (auto i : testCases)
    {
        average = 0;
        for(int j = 0; j < 3; j++)
        {
        testCase.clear();
        string curLine;
        fileIN.open(i);
        while( fileIN >> curLine)
        {
            testCase.push_back(stoi(curLine));
        }
        if(j == 0){size = testCase.size();}
        start = chrono::system_clock::now(); 
        qsort(&testCase[0], size, sizeof(int), compare);
        end = chrono::system_clock::now();
        elapsed_seconds = end - start;
         average += elapsed_seconds.count();
        }
        fileOUT << size << ',' << average/3 << endl;
        fileIN.close();
    }
    std::cout << "FINISHED QSORT" << endl;

     fileOUT << endl << "ShellSort" << endl;
    for (auto i : testCases)
    {
        average = 0;
        for(int j = 0; j < 3; j++)
        {
        testCase.clear();
        string curLine;
        fileIN.open(i);
        while( fileIN >> curLine)
        {
            testCase.push_back(stoi(curLine));
        }
        if(j == 0){size = testCase.size();}
        start = chrono::system_clock::now(); 
        shellSort(testCase, size);
        end = chrono::system_clock::now();
        elapsed_seconds = end - start;
         average += elapsed_seconds.count();
        }
        fileOUT << size << ',' << average/3 << endl;
        fileIN.close();
    }
    std::cout << "FINISHED ShellSort" << endl;
    return 0; 
}