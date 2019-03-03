using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public class Square {
    public int N;
    private int [] square;
    public int size() { return N; }
    private int rowCol2Index(int row, int col) { return N*row + col; }
    
    public Square(int _n)  {
        N = _n;
        square = new int[N*N];
    }
    
    public int get(int row, int col) { return square[rowCol2Index(row,col)]; }
    public void set(int row, int col, int value) { square[rowCol2Index(row,col)] = value; }
    
    public void print() { print(" ", 3); }
    public void print(String sep) { print(sep, 3); }
    public void print(String sep, int width) {
        int row, col;
        
        for (row=0; row < N; ++row) {
            for (col=0; col < N; ++col) {
                if ((col > 0) && (sep != ""))
                {
                    Console.Write(sep);
                }
                String s = String.Format("{0}", get(row, col).ToString(string.Format("D{0}",Convert.ToString(size()*size()).Length)));
                Console.Write(s);
            }
            Console.WriteLine("");
        }
    }
}
