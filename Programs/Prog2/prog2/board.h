#include <iostream>
#include <string> 
#include <vector>
#include "cell.h"
#include "stack.h"
#include "queue.h"

using namespace std;

class Board
{
    public:
        int width;
        int height;
        vector<vector<Cell> > maze;
        Queue<Cell> queue;
        Stack<Cell> stack;
        Stack<Cell> path;
        int pathLen;
        Board();
        void WriteBoard(vector<vector<Cell> > board, string output, bool pathExist);
        void CreateBoard(std::string fileName);
        bool SearchBoard();
        void IsConnected();
};