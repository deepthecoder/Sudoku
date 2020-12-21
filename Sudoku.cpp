#include "Sudoku.h"

namespace ds {

void Sudoku::readFrom1DArray(int *board) {

  int k=0;
  for(int i=0;i<9;i++)
  {
      for(int j=0;j<9;j++)
      {
          grid[i][j]=board[k++];
      }
  }
}


void Sudoku::solve()
{
   solver();
}


bool Sudoku::solver()
{
 
    int row,col;
    if(!findUnassign(row,col))
        return true;
    for(int i=0;i<=9;i++)
    {
        if(isSafe(row,col,i))
        {
            grid[row][col]=i;
            if(solver())
                return true;
            grid[row][col]=0;
        }
    }
    return false;
}

bool Sudoku::findUnassign(int &row,int &col)
{
   for (row = 0; row < 9; row++)
        for (col = 0; col < 9; col++)
            if (grid[row][col] == 0)
                return true;
    return false;
}

bool Sudoku::usedRow(int row,int num)
{
    for(int i=0;i<9;i++)
    {
        if(grid[row][i]==num)
            return true;
    }
    return false;
}

bool Sudoku::usedCol(int col,int num)
{
    for(int i=0;i<9;i++)
    {
        if(grid[i][col]==num)
            return true;
    }
    return false;
}

bool Sudoku::usedBox(int row,int col,int num)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(grid[i+row][j+col]==num)
                return true;
        }
    }
    return false;
}

bool Sudoku::isSafe( int row,int col, int num)
{

    return !usedRow(row,num)&& !usedCol(col,num) && !usedBox(row-row%3,col-col%3,num)&& grid[row][col]==0;
}

} // namespace ds
