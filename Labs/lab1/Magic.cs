using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public class Magic
{
    static void Main()
    {
        Console.WriteLine("How many units (length wise) should the square be?");
        int gridSize = Convert.ToInt32(Console.ReadLine());

        Square grid = new Square(gridSize);
        if (gridSize % 4 == 0)
        {
            DoublyEven(gridSize, grid);
        }
        else if (gridSize % 2 == 1)
        {
            Odd(gridSize, grid);
        }
        grid.print(" | ", gridSize);
        Console.WriteLine("The sums should be {0}", GetAnswer(gridSize));
        Console.ReadLine();
    }

    public static void DoublyEven(int gridSize, Square grid)
    {
        int row, col, forward, backward;

        forward = 1; backward = gridSize * gridSize;

        for (row = 0; row < gridSize; ++row)
        {
            int m = row / 2;
            for (col = 0; col < gridSize; ++col, ++forward, --backward)
            {
                bool isForward = (row < gridSize / 4 || row > gridSize - ((gridSize / 4) + 1));
                if (col < gridSize / 4 || col > gridSize - ((gridSize / 4) + 1) && isForward)
                {
                    grid.set(row, col, forward);
                }
                else
                {
                    grid.set(row, col, backward);
                }
            }
        }
    }

    public static void Odd(int gridSize, Square grid)
    {
        int row, col, forward;

        forward = 1;
        col = gridSize / 2;
        row = 0;
        while (forward <= gridSize * gridSize)
        {
            grid.set(row, col, forward);
            --row;
            ++col;
            ++forward;
            if (row == -1)
            {
                row = gridSize - 1;
            }
            if (col == gridSize)
            {
                col = 0;
            }
            if (grid.get(row, col) != 0)
            {
                if (row == gridSize - 1 && col == 0)
                {
                    row = 1;
                    col = gridSize - 1;
                }
                else
                {
                    row += 2;
                    --col;
                }
            }
        }
    }
    public static string GetAnswer(int num)
    {
        return Convert.ToString(num * ((num * num) + 1) / 2);
    }

}


