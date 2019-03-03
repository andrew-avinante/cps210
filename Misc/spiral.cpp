#include <functional>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
int main() 
{
    long long size, find, itter, orientation, length, prevLen;
    std::cin >> size >> find;
    queue<pair<long long, long long>> answer;
    while (size != 0 && find != 0)
    {
        length = size;
        prevLen = length;
        itter = 1;
        orientation = 0;
        //long long array[size][size];
        long long x = size - 1, y = size - 1, counter = size * size; 
        if(size * size == find)
        {
            x = size-1;
            y = size-1;
        }
        else
        {
            while(counter != find)
            {
                //array[y][x] = counter;
                //cout << x << " " << y << ": " << array[y][x] << endl;
                length--;
                if(length == 0)
                {
                    itter++;
                    if(itter == 2)
                    {
                        itter = 0;
                        length = prevLen - 1;
                        prevLen = length;
                    }
                    else
                    {
                        length = prevLen;
                    }
                    if(orientation + 1 <= 3)
                    {
                        orientation++;
                    }
                    else
                    {
                        orientation = 0;
                    }
                }
                if(counter - length > find)
                {
                    if(orientation == 0)
                    {
                        y -= length;
                    }
                    else if(orientation == 1)
                    {
                        x -= length;
                    }
                    else if(orientation == 2)
                    {
                        y += length;
                    }
                    else if(orientation == 3)
                    {
                        x += length;
                    }
                    counter = counter - length;
                    length = 1;
                }
                else
                {
                    if(orientation == 0)
                    {
                        y--;
                    }
                    else if(orientation == 1)
                    {
                        x--;
                    }
                    else if(orientation == 2)
                    {
                        y++;
                    }
                    else if(orientation == 3)
                    {
                        x++;
                    }
                    counter--;
                }
                // if(orientation == 0)
                // {
                //     y--;
                // }
                // else if(orientation == 1)
                // {
                //     x--;
                // }
                // else if(orientation == 2)
                // {
                //     y++;
                // }
                // else if(orientation == 3)
                // {
                //     x++;
                // }
            }
        }
        pair <long long, long long> pairs;
        pairs.first = y + 1;
        pairs.second = x + 1;
        answer.push(pairs);
        std::cin >> size >> find;
    }
    while(!answer.empty())
    {
        cout << "Line = " << answer.front().first << ", " << "column = " << answer.front().second << "." << endl;
        answer.pop();
    }
    return 0;
}