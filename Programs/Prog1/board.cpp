#include <iostream>
#include "board.h"
using namespace std;


Board::Board(int h, int w, int g)
{
    width = w;
    height = h;
    generations = g;
    genCount = 0;
    CreateBoard(width, height,  ecosystem = new Cell*[width]);
    CreateBoard(width, height,  prevEco = new Cell*[width]);
    CreateBoard(width, height,  prevPrevEco = new Cell*[width]);
    PopulateCells();
    CountGen();
    // prevGen = ecosystem;
    PrintBoard(ecosystem);
    cout << "INITIAL GENERATION: 0" << endl << endl;
}

void Board::CreateBoard(int w, int h, Cell** board)
{     
    for(int i = 0; i < w; i++)
    {
        board[i] = new Cell[h];
        for (int j = 0; j < h; j++)
        {
            board[i][j].loc.col = j;
            board[i][j].loc.row = i;
            board[i][j].KillCell();
            board[i][j].ResetNeighbor();
        }
    }
}

void Board::PopulateCells()
{
    int lifeForms =  3 + (rand() % (width * height));
    for (int i = 0; i < lifeForms; i++)
    {
        int randRow = 1 + (rand() % (width)-1);
        int randCol = 1 + (rand() % (height)-1);
        ecosystem[randRow][randCol].BirthCell();
        // ecosystem[1][0].BirthCell();
        // ecosystem[0][1].BirthCell();
        // ecosystem[1][2].BirthCell();
    }
}

void Board::PrintBoard(Cell** board)
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (board[i][j].isAlive)
            {
                cout << "[ x ]";
            }
            else
            {
                cout << "[   ]";
            }
        }
        cout << endl;
    }
}

void Board::PrintPrevBoard()
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (prevPrevEco[i][j].isAlive)
            {
                cout << "[ x ]";
            }
            else
            {
                cout << "[   ]";
            }
        }
        cout << endl;
    }
}

void Board::FindNeighbors()
{
    Cell currentCell;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            currentCell = ecosystem[i][j];
            ecosystem[i][j].ResetNeighbor();
            if (currentCell.loc.row != 0 && currentCell.loc.col != 0 && ecosystem[i-1][j-1].isAlive)
            {
                ecosystem[i][j].AddNeighbor();
                //cout << ecosystem[i][j].loc.row << ' ' << ecosystem[i][j].loc.col << " Top Left;" << endl;
            }

            if (currentCell.loc.row != 0 && ecosystem[i-1][j].isAlive)
            {
                ecosystem[i][j].AddNeighbor();
                //cout << ecosystem[i][j].loc.row << ' ' << ecosystem[i][j].loc.col << " Top;" << endl;
            }

            if (currentCell.loc.row != 0 && currentCell.loc.col != height - 1 && ecosystem[i-1][j+1].isAlive)
            {
                ecosystem[i][j].AddNeighbor();
                //cout << ecosystem[i][j].loc.row << ' ' << ecosystem[i][j].loc.col << " Top Right;" << endl;
            }

            if (currentCell.loc.col != height - 1 && ecosystem[i][j+1].isAlive)
            {
                ecosystem[i][j].AddNeighbor();
                //cout << ecosystem[i][j].loc.row << ' ' << ecosystem[i][j].loc.col << " Right;" << endl;
            }

            if (currentCell.loc.row != width - 1 && currentCell.loc.col != height - 1 && ecosystem[i+1][j+1].isAlive)
            {
                ecosystem[i][j].AddNeighbor();
                //cout << ecosystem[i][j].loc.row << ' ' << ecosystem[i][j].loc.col << " Bottom Right;" << endl;
            }

            if (currentCell.loc.row != width - 1 && ecosystem[i+1][j].isAlive)
            {
                ecosystem[i][j].AddNeighbor();
                //cout << ecosystem[i][j].loc.row << ' ' << ecosystem[i][j].loc.col << " Bottom;" << endl;
            }

            if (currentCell.loc.row != width - 1 && currentCell.loc.col != 0 && ecosystem[i+1][j-1].isAlive)
            {
                ecosystem[i][j].AddNeighbor();
                //cout << ecosystem[i][j].loc.row << ' ' << ecosystem[i][j].loc.col<< " Bottom Left;" << endl;
            }
            
            if (currentCell.loc.col != 0 && ecosystem[i][j-1].isAlive)
            {
                ecosystem[i][j].AddNeighbor();
                //cout << ecosystem[i][j].loc.row << ' ' << ecosystem[i][j].loc.col << " Left;" << endl;
            }
            //cout << endl;
        }
    }
}

void Board::CountGen()
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (ecosystem[i][j].isAlive)
            {
                AddCurrentGen();
            }
        }
    }
}

void Board::Spawn()
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (ecosystem[i][j].GetNeighbor() == 3)
            {
                ecosystem[i][j].BirthCell();
            }
        }
    }
}

void Board::Kill()
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (ecosystem[i][j].GetNeighbor() < 2 || ecosystem[i][j].GetNeighbor() > 3)
            {
                ecosystem[i][j].KillCell();
            }
        }
    }
}

void Board::DebugPrint()
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            cout << ecosystem[i][j].loc.row << ' ' << ecosystem[i][j].loc.col << " --> " <<  ecosystem[i][j].GetNeighbor() << ' ' << ecosystem[i][j].isAlive << endl;
        }
    }
    cout << endl;
}

void Board::SetPrevGen(Cell** previous, Cell** current)
{
    for(int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if(current[i][j].isAlive)
            {
                previous[i][j].BirthCell();
            }
            else
            {
                previous[i][j].KillCell();
            }
        }
    }
}

bool Board::AreEqual()
{
    for(int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if(ecosystem[i][j].isAlive != prevEco[i][j].isAlive && prevPrevEco[i][j].isAlive != ecosystem[i][j].isAlive)
            {
                return false;
            }
        }
    }
    return true;
}


