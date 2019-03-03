#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <string>
#include <map>

using namespace std;

priority_queue<int> FindLengths(vector<vector<int>> &grid, vector<vector<int>> &visits, int row, int col)
{
    priority_queue<int> lengths;
    int checks[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (int i = 100; i > -1; i--)
    {
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if(grid[r][c] == i)
                    {
                        if(checks[j][0] + r != -1 && checks[j][0] + r != row && checks[j][1] + c != -1 && checks[j][1] + c != col )
                        {
                            if(visits[checks[j][0] + r][checks[j][1] + c] != -1 && visits[checks[j][0] + r][checks[j][1] + c] + 1 > visits[r][c] && grid[checks[j][0] + r][checks[j][1] + c] != grid[r][c])
                            {
                                lengths.push(visits[checks[j][0] + r][checks[j][1] + c] + 1);
                                visits[r][c] = visits[checks[j][0] + r][checks[j][1] + c] + 1;
                            }
                            else if(visits[r][c] == -1)
                            {
                                lengths.push(1);
                                visits[r][c] = 1;
                            }
                            //cout << "HEIGHT: " << i << endl << "LENGTH" << visits[r][c] << endl << endl;
                        }
                    }
                }
            }
        }
    }
    return lengths;
}

int main() 
{
    int testCases;
    vector<string> slopes;
    vector<int> slopeLengths;
    cin >> testCases;
    while (testCases--) 
    {
        string slopeName;
        int row, col;
        cin >> slopeName >> row >> col;
        vector<vector<int>> grid(row, vector<int>(col));
        vector<vector<int>> visits(row, vector<int>(col));
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                cin >> grid[i][j];
                visits[i][j] = -1;
            }
        }
        slopes.push_back(slopeName);
        slopeLengths.push_back(FindLengths(grid, visits, row, col).top());
    }

    for (int i = 0; i < slopes.size(); i ++)
    {
        cout << slopes[i] << ": " << slopeLengths[i] << endl;
    }

    return 0;
}