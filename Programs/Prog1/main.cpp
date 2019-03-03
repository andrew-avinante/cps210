#include <iostream>
#include "board.h"
using namespace std;

int main()
{
    srand(time(0));
    int w;
    int h;
    int g;
    int ivl;
    cout << "Input height: ";
    cin >> h;
    cout << "Input width: ";
    cin >> w;
    cout << "Input generations: ";
    cin >> g;
    cout << "Input print interval (put 0 if you just want initial and final prints): ";
    cin >> ivl;

    char prntPrevDeath;
    Board mainBoard = Board(w,h,g);
    cout << "BREEDING" << endl << endl;
    for(int i = 0; i < mainBoard.generations; i++)
    {
        mainBoard.ResetCurrentGen();
        mainBoard.SetPrevGen(mainBoard.prevPrevEco, mainBoard.prevEco);
        mainBoard.SetPrevGen(mainBoard.prevEco, mainBoard.ecosystem);
        mainBoard.FindNeighbors();
        mainBoard.Spawn();
        mainBoard.Kill();
        mainBoard.CountGen();
        if((mainBoard.AreEqual()) && i != 0)
        {
            mainBoard.PrintBoard(mainBoard.ecosystem);
            if(mainBoard.GetCurrentGen()== 0)
            {
                cout << "ALL LIFE FORMS HAVE DIED OUT ON GENERATION: " << i << endl;
                cout << "DO YOU WANT TO DISPLAY GENERATION BEFORE EXTINCTION? (Y or N): ";
                cin >> prntPrevDeath;
                if(tolower(prntPrevDeath) == 'y')
                {
                    mainBoard.PrintBoard(mainBoard.prevPrevEco);
                    cout << "CURRENTLY DISPLAYING PREVIOUS BOARD BEFORE EXTINCTION" << endl;
                }
            }
            else
            {
                cout << "THE ENVIRONMENT STABILIZED ON GENERATION: " << i+1 << endl;
                cout << "LIFE FORMS THAT SURVIVED: " << mainBoard.GetCurrentGen() << endl;
            }
            return 0;
        }
        if(ivl != 0 && i % ivl == 0)
        {
            mainBoard.PrintBoard(mainBoard.ecosystem);
            cout << "GENERATION: " << i+1 << endl << endl;
        }
    }
    // mainBoard.PrintPrevBoard();
    mainBoard.PrintBoard(mainBoard.ecosystem);
    cout << "GENERATION: " << mainBoard.generations << endl << endl; //<< ' ' << mainBoard.AreEqual()
    cout << "LIFE FORMS THAT SURVIVED: " << mainBoard.GetCurrentGen() << endl;
    return 0;
}