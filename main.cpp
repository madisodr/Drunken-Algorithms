/*
 * Author: Daniel R Madison
 * Copyright (C) 2016
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "drunk.h"
#include "sorting.h"
#include "sudoku.h"
#include "tree.h"
#include "trie.h"


#include <iostream>
#include <vector>

using namespace std;

struct node {
  int id;
  int parent;
  string name;
};


node family[] = { 
  {1, 0, "Thingol"},
  {2, 1, "Luthien"},
  {3, 2, "Dior"},
  {4, 3, "Elured"},
  {5, 3, "Elurin"},
  {6, 3, "Elwing"},
  {7, 6, "Elros"},
  {8, 6, "Elrond"},
  {9, 7, "Aragorn"},
  {10, 8, "Arwen"},
  {11, 8, "Elladan"},
  {12, 8, "Elrohir"},
  {13, 0, "Olwe"},
  {14, 13, "Earwen"},
  {15, 14, "Finrod"},
  {16, 14, "Orodreth"},
  {17, 14, "Angrod"},
  {18, 14, "Aegnor"},
  {19, 14, "Galadriel"},
  {20, 14, "Celebrian"},
  {21, 20, "Arwen"},
  {22, 0, "Elmo"},
  {23, 22, "Galadhon"},
  {24, 23, "Celeborn"},
  {25, 23, "Galathil"}
};
void testTree() {
  Graph* g = new Graph();
  unsigned int familySize = sizeof(family)/sizeof(family[0]);

  for(size_t i = 0; i < familySize; i++) {
    g->addNode(new Node(family[i].id, family[i].parent, family[i].name));
  }

  delete g;
}


void sudokuTest() {
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
  if(!puzzle->IsLegalBoard()) {
    drunkout("Illegal board.", cERROR);
  }
  puzzle->print();

  if(puzzle->solve())
    puzzle->print();
  else
    drunkout("No solution.", cINFO);

  delete puzzle;

}

int main() { 
  sudokuTest();
  return 0;
}
