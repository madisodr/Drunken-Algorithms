#include "Sudoku.h"
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

void Sudoku::test() {
  vector< vector<int> > _grid = 
  {{3, 0, 6, 5, 0, 8, 4, 0, 0},
    {5, 2, 0, 0, 0, 0, 0, 0, 0},
    {0, 8, 7, 0, 0, 0, 0, 3, 1},
    {0, 0, 3, 0, 1, 0, 0, 8, 0},
    {9, 0, 0, 8, 6, 3, 0, 0, 5},
    {0, 5, 0, 0, 9, 0, 6, 0, 0},
    {1, 3, 0, 0, 0, 0, 2, 5, 0},
    {0, 0, 0, 0, 0, 0, 0, 7, 4},
    {0, 0, 5, 2, 0, 6, 3, 0, 0}};

  Sudoku* puzzle = new Sudoku( _grid );

  if(puzzle->solve())
    puzzle->print();
  else
    cout << "No solution found\n";

}
