#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

void trim(string& s)
{
    size_t p = s.find_first_not_of(" \t");
    s.erase(0, p);

    p = s.find_last_not_of(" \t");
    if (string::npos != p)
    s.erase(p+1);
}

int main()
{
    vector<int> output;
    int num;
    string input;
    auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1);};
    std::priority_queue<int> minHeap;
    std::priority_queue<int, vector<int>, greater<int>> maxHeap;
    while(getline(cin, input))
    {
        if(input.empty())
        {
            break;
        }
        trim(input);
        num = stoi(input);
        if(minHeap.empty())
        {
            minHeap.push(num);
        }
        else if(maxHeap.empty())
        {
            if(num > minHeap.top())
            {
                maxHeap.push(num);
            }
            else
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(num);
            }
        }
        else if(minHeap.top() > num)
        {
            minHeap.push(num);
        }
        else if(maxHeap.top() < num)
        {
            maxHeap.push(num);
        }
        else
        {
            minHeap.push(num);
        }
        if(minHeap.size() == maxHeap.size() + 2)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        else if (minHeap.size() == maxHeap.size()-2)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        output.push_back((minHeap.size() > maxHeap.size()) ? minHeap.top() : (minHeap.size() < maxHeap.size()) ? maxHeap.top() : ((maxHeap.top() + minHeap.top()) / 2));
    }

    for(int i : output)
    {
        cout << i << endl;
    }

    return 0;
}