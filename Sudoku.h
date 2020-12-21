#ifndef __SUDOKU_H__
#define __SUDOKU_H__

#include <iostream>

namespace ds {

class Sudoku {
private:
  int grid[9][9];

public:
  Sudoku() {}

  void readFrom1DArray(int *grid);
  void solve();
  bool solver();
  bool findUnassign(int &row, int &col);
  bool usedRow(int,int);
  bool usedCol(int,int);
  bool usedBox(int , int, int);
  bool isSafe(int,int,int);
  void print1D() const {
    for (int row = 0; row < 9; row++) {
      for (int col = 0; col < 9; col++) {
        if (row != 0 || col != 0)
          std::cout << " ";
        std::cout << grid[row][col];
      }
    }
  }
};

} // namespace ds

#endif // __SUDOKU_H__
