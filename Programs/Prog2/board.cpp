#include <iostream>
#include <fstream> 
#include <algorithm>
#include "board.h"
using namespace std;


Board::Board()
{
}

void Board::CreateBoard(string fileName)
{     
    ifstream file;
    file.open(fileName);
    string curLine = "";
    int rowCount = 0;
    int colCount = 0;
    while(file >> curLine)
    {
        vector<Cell> row;
        for(char i : curLine)
        {
            Cell cell = Cell();
            cell.SetCord(rowCount, colCount);
            if(i == '1')
            {
                cell.SetSolid();
                cell.SetVisitNum(1);
            }
            else if(toupper(i) == 'E')
            {
                cell.SetEntrance();
                cell.SetVisitNum(2);
                queue.push(cell);
            }
            else
            {
                cell.SetVoid();
                cell.SetVisitNum(0);
            }
            row.push_back(cell);
            ++colCount;
        }
        maze.push_back(row);
        colCount = 0;
        ++rowCount;
    }
    width = maze[0].size();
    height = maze.size();
    file.close();
}

void Board::WriteBoard(vector<vector<Cell> > board, string output, bool pathExist)
{
    ofstream file;
    file.open(output);
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            (board[i][j].isPath && pathExist) ? ((board[i][j].GetCell() != 'E') ? file << ' ' : file << 'E') : file << board[i][j].GetCell();
        }
        file << endl;
    }
    if(pathExist)
    {
        file << endl << "COORDS ENTRANCE TO EXIT:" << endl;
        while(!path.empty())
        {
            Cell i = path.top();
            file << '(' << i.GetCord() << ')' << endl;
            path.pop();
        }
        file << "TOTAL MOVES: " << to_string(pathLen - 1) << " (NOT INCLUDING 'E')";
    }
    else
    {
        file << "NO PATH EXISTS!";
    }
}

bool Board::SearchBoard()
{
    vector<int> checks = {-1,0,0,1,1,0,0,-1};
    int visitNum = 3;
    int i, j;
    bool found = false;
    while(queue.size() != 0)
    {
        Cell cellToCheck = queue.front();
        stack.push(cellToCheck);
        queue.pop();
        if((cellToCheck.GetCell() == '0' && (cellToCheck.GetCol() == 0 || cellToCheck.GetRow() == 0 || cellToCheck.GetCol() == width - 1 || cellToCheck.GetRow() == height - 1)) || (cellToCheck.GetCell() == 'E' && width == 1 && height == 1))
        {
            return true;
        }
        for(i = 0, j = 1; j < 8; i += 2, j += 2)
        {
            Cell cellToAdd;
            if(cellToCheck.checkSides(checks[i], checks[j], height, width) && maze[cellToCheck.GetRow() + checks[i]][cellToCheck.GetCol() + checks[j]].GetVisitNum() == 0)
            {   
                maze[cellToCheck.GetRow() + checks[i]][cellToCheck.GetCol() + checks[j]].SetVisitNum(cellToCheck.GetVisitNum() + 1);
                cellToAdd = maze[cellToCheck.GetRow() + checks[i]][cellToCheck.GetCol() + checks[j]];
                queue.push(cellToAdd);
            }
        }
    }
    return false;
}

void Board::IsConnected()
{
    Cell curCell, cellToCheck;
    curCell = stack.top();
    path.push(stack.top());
    stack.pop();
    vector<int> checks = {-1,0,0,1,1,0,0,-1};
    int i, j;
    while(stack.size() != 0)
    {
        cellToCheck = stack.top();
        for(i = 0, j = 1; j < 8; i += 2, j += 2)
        {
            if(curCell.GetCol() + checks[j] == cellToCheck.GetCol() && curCell.GetRow() + checks[i] == cellToCheck.GetRow() && cellToCheck.GetVisitNum() == curCell.GetVisitNum() - 1)
            {
                
                maze[curCell.GetRow()][curCell.GetCol()].SetPath();
                path.push(cellToCheck);
                curCell = cellToCheck;
            }
        }
        stack.pop();
    }
    pathLen = path.size();
}