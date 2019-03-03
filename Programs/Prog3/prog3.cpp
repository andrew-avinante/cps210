#include <functional>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

vector<pair<string, int>> inputVector;
vector<int> sums;
vector<vector<int>> matrix;

void getInput()
{
    pair<string,int> p;
    string input;
    char delimiter = ' ';
    while (cin >> p.first >> p.second)
    {
        inputVector.push_back(p);
    }
    sort(inputVector.begin(), inputVector.end());
}

void createMatrix()
{
    int count = 0;
    int previous;
    vector<int> column(inputVector.size());
    for (auto const& i : inputVector)
    {
        sums.push_back(!sums.empty() ? sums[previous] + i.second : i.second);
        previous = count;
        column[count] = i.second;
        matrix.push_back(column);
        ++count;
        column.clear();
        column.resize(inputVector.size());
    }
}

int findSmallestRoot()
{
    int fast[16000];
    int rootOffset = (8*(matrix.size()/1000)) - 4;
    fill_n(fast, 16000, -1);
    int startingPoint = 1, root = 0;
    int cord1, cord2;
    pair<int, int> minNum;
    for(int i = 0; i < matrix.size(); ++i, ++startingPoint)
    {
        for(int x = startingPoint, y = 0; x < matrix.size(); ++x, ++y)
        {
            if(fast[y] == -1)
            {
                fast[y] = y;
            }
            minNum = {fast[y], matrix[y][x-1]};
            if (startingPoint != 1)
            {
                for(int j = fast[y], k = fast[y] + 2; k <= x; ++j, ++k)
                {
                    cord1 = matrix[y][j], cord2 = matrix[k][x];
                    minNum = {( minNum.second > cord1 + cord2) ? j : minNum.first, ( minNum.second > cord1 + cord2) ? cord1 + cord2 : minNum.second};
                }
                
                minNum = {( minNum.second > matrix[y][x-1]) ? x : minNum.first,( minNum.second > matrix[y][x-1]) ? matrix[y][x-1] : minNum.second};
                minNum = {( minNum.first > matrix[y+1][x]) ? x : minNum.first, ( minNum.second > matrix[y+1][x]) ? matrix[y+1][x] : minNum.second};
                matrix[y][x] = minNum.second + sums[x] - ((y==0) ? 0 : sums[y-1]);
            }
            else
            {
                cord1 = matrix[y][y], cord2 = matrix[x][x];
                matrix[y][x] = (( cord1 < cord2 ) ? cord1 : cord2) + sums[x] - ((y==0) ? 0 : sums[y-1]);
            }
            root = minNum.first;        
        }
    }
    return root;
}

int main() 
{
    getInput();
    createMatrix();
    cout << inputVector[findSmallestRoot() + 1].first << " " << matrix[0][matrix.size()-1] << endl;
    return 0;
}