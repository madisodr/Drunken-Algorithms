#ifndef __sudoku_h__
#define __sudoku_h__

#include <vector>

#define UNASSIGNED 0

class Sudoku {
public:
	Sudoku( std::vector< std::vector<int> > _grid);
	~Sudoku();
	bool solve();
	bool isSafe( int row, int col, int num );
	bool findUnassigned( int& row, int& col );
	bool inRow( int row, int num );
	bool inCol( int col, int num );
	bool inBox( int boxStartRow, int boxStartCol, int num );

	void print();
private:
	std::vector< std::vector<int> > m_grid;
	int m_size;
};

#endif