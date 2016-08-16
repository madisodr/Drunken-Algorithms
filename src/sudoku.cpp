#include "../includes/sudoku.h"
#include <iostream>
#include <vector>

using namespace std;

Sudoku::Sudoku( vector< vector<int> > _grid ) {
  m_grid = _grid;
  m_size = (int)_grid.size();
}

Sudoku::~Sudoku() {}

bool Sudoku::solve() {
  int row, col;
  if(!findUnassigned( row, col ))
    return true;

  for(int num = 1; num <= m_grid.size(); num++) {
    if(isSafe( row, col, num )) {
      m_grid[row][col] = num;
      if(solve())
        return true;

      m_grid[row][col] = UNASSIGNED;
    }

  }
  return false;
}

bool Sudoku::isSafe( int row, int col, int num ) {
  return (!inRow( row, num ) && !inCol( col, num ) && !inBox( row - row % 3, col - col % 3, num ));
}

bool Sudoku::findUnassigned( int & row, int & col ) {
  for(row = 0; row < m_size; row++) {
    for(col = 0; col < m_size; col++) {
      if(m_grid[row][col] == UNASSIGNED)
        return true;
    }
  }

  return false;
}

bool Sudoku::inRow( int row, int num ) {
  for(int col = 0; col < m_size; col++) {
    if(m_grid[row][col] == num)
      return true;
  }
  return false;
}

bool Sudoku::inCol( int col, int num ) {

  for(int row = 0; row < m_size; row++) {
    if(m_grid[row][col] == num)
      return true;
  }

  return false;
}

bool Sudoku::inBox( int boxStartRow, int boxStartCol, int num ) {
  for(int row = 0; row < 3; row++) {
    for(int col = 0; col < 3; col++) {
      if(m_grid[row + boxStartRow][col + boxStartCol] == num)
        return true;
    }
  }

  return false;
}

void Sudoku::print() {
  for(int row = 0; row < m_size; row++) {
    for(int col = 0; col < m_size; col++) {
      cout << m_grid[row][col] << " ";
    }
    cout << "\n";
  }
  cout << "\n\n";
}

