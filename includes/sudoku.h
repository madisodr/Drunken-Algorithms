#ifndef __sudoku_h__
#define __sudoku_h__

#include <vector>

#define UNASSIGNED 0
#define BOXSIZE 3
#define BOARDSIZE 9

class Sudoku {
  public:
    Sudoku( std::vector< std::vector<int> > _grid);
    ~Sudoku();
    bool IsLegalBoard();
    bool solve();
    bool findUnassigned( std::size_t& row, std::size_t& col );
    bool isSafe(const std::size_t row, const std::size_t col, const int num );
    bool inRow(const std::size_t row, const int num );
    bool inCol(const std::size_t col, const int num );
    bool inBox(const std::size_t boxStartRow, const std::size_t boxStartCol, const int num );

    void print();
  private:
    std::vector< std::vector<int> > m_grid;
    int m_size;
};

#endif
