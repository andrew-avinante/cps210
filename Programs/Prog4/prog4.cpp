#include <functional>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include "adjlist.h"
#include <list>

using namespace std;


int main() 
{
    int v1, v2, weight;
    AdjList<int> adj;
    while(cin >> v1 >> v2 >> weight)
    {
        adj.addEdge(v1, v2, weight);
    }
    adj.processOutput();
    return 0;
}