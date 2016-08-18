#include "../includes/sudoku.h"
#include <iostream>
#include <vector>

using namespace std;

Sudoku::Sudoku( vector< vector<int> > _grid ) {
  m_grid = _grid;
  m_size = (int)_grid.size();
}

bool Sudoku::IsLegalBoard() {
  if(m_grid.size() != BOARDSIZE)
    return false;
  
  for(auto it : m_grid) {
    if(it.size() != BOARDSIZE)
      return false;
  }
  
  return true;
}

Sudoku::~Sudoku() {}

bool Sudoku::solve() {
  size_t row, col;
  if(!findUnassigned( row, col ))
    return true;

  for(size_t num = 1; num <= BOARDSIZE; num++) {
    if(isSafe( row, col, num )) {
      m_grid[row][col] = num;
      if(solve())
        return true;

      m_grid[row][col] = UNASSIGNED;
    }

  }
  return false;
}

bool Sudoku::isSafe(const size_t row, const size_t col, const int num ) {
  return (!inRow( row, num ) && !inCol( col, num ) && !inBox( row - row % BOXSIZE, col - col % BOXSIZE, num ));
}

bool Sudoku::findUnassigned( size_t & row, size_t & col ) {
  for(row = 0; row < BOARDSIZE; row++) {
    for(col = 0; col < BOARDSIZE; col++) {
      if(m_grid[row][col] == UNASSIGNED)
        return true;
    }
  }

  return false;
}

bool Sudoku::inRow(const size_t row, const int num ) {
  for(size_t col = 0; col < BOARDSIZE; col++) {
    if(m_grid[row][col] == num)
      return true;
  }
  return false;
}

bool Sudoku::inCol( const size_t col, const int num ) {

  for(size_t row = 0; row < BOARDSIZE; row++) {
    if(m_grid[row][col] == num)
      return true;
  }

  return false;
}

bool Sudoku::inBox( const size_t boxStartRow, const size_t boxStartCol, const int num ) {
  for(size_t row = 0; row < BOXSIZE; row++) {
    for(size_t col = 0; col < BOXSIZE; col++) {
      if(m_grid[row + boxStartRow][col + boxStartCol] == num)
        return true;
    }
  }

  return false;
}

void Sudoku::print() {
  for(size_t row = 0; row < BOARDSIZE; row++) {
    for(size_t col = 0; col < BOARDSIZE; col++) {
      cout << m_grid[row][col] << " ";
    }
    cout << "\n";
  }
  cout << "\n\n";
}

