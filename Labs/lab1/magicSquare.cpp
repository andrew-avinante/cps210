#include "square.h"

bool isForward(int rowMod4, int colMod4) {
    switch (rowMod4) {
    case 0:
    case 3:
        return (0 == colMod4 || 3 == colMod4);
    case 1:
    case 2:
        return (1 == colMod4 || 2 == colMod4);
    }
    return false;
      
}

void printDoublyEvenSquare(int N) {
    int fwd=1, back=N*N, row, col, nDiv4=N/4;
    Square square(N);
    
    for (row=0; row < N; ++row) {
        for (col=0; col < N; ++col, ++fwd, --back) {
            square.set(row, col, 
                (isForward(row/nDiv4, col/nDiv4) ? fwd : back));
        }
    }
    square.print(std::cout) << std::endl;
}

void Odd(int N)
{
    int row, col, forward;
    Square square(N);
    forward = 1;
    col = N / 2;
    row = 0;
    while (forward <= N * N)
    {
        square.set(row, col, forward);
        --row;
        ++col;
        ++forward;
        if (row == -1)
        {
            row = N - 1;
        }
        if (col == N)
        {
            col = 0;
        }
        if (square.get(row, col) != 0)
        {
            if (row == N - 1 && col == 0)
            {
                row = 1;
                col = N - 1;
            }
            else
            {
                row += 2;
                --col;
            }
        }
    }
    square.print(std::cout) << std::endl;
}

int main() 
{
    int gridSize = 2 ;
    while(gridSize % 2 == 0 && gridSize % 4 != 0)
    {
        std::cout << "What is the grid's width? (Must be divisible by 4 or odd): ";
        std::cin >> gridSize;
        if(gridSize % 2 == 0 && gridSize % 4 != 0) 
        {
            std::cout << "\nThe number you entered is not divisible by 4 or odd!\n";
        }
    }
    std::cout << "\n";
    if(gridSize % 4 == 0)
    {
        printDoublyEvenSquare(gridSize);
    }
    else if (gridSize % 2 == 1)
    {
        Odd(gridSize);
    }
    return 0;
}