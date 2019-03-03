#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <vector>
#include <fstream> 
#include <random> 
using namespace std;

template <typename Number>
Number fastExp1(Number x, unsigned int n)
{
    switch(n)
    {
        case 0: return Number(1);
        case 1: return x;
        case 2: return (x * x);
        case 3: return (x * x * x);
    }
    Number ans = fastExp1(x, n >> 1);
    ans *= ans;
    if (n & 0x01) { ans *= x; } 
    return ans;
}

int main()
{
    int num, count = 1;
    ofstream fileOUT;
    for(int i = 10; i <= 24; i++, count++)
    {
        fileOUT.open("test" +to_string(count) + ".txt");
        num = fastExp1(2, i);
        for(int j = 0; j <= num; j++)
        {
            fileOUT << rand() % 10000000 << endl;
        }
        fileOUT.close();
        cout << "test" << count << ".txt, ";
    }
    return 0; 
}