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

#ifndef __drunk_search_h__
#define __drunk_search_h__

#include <vector>

using namespace std;

struct Node {
  int key;
  Node* left;
  Node* right;
};

class BinarySearch {
  public:
    BinarySearch(vector<int>& A, int key);
    ~BinarySearch();

    int search(vector<int>& A, int imin, int imax, int key);
};

// GRAPH RELATED SEARCHING
class BinaryTree {

  public:
    BinaryTree();
    ~BinaryTree();
    Node* getRoot() { return root; }
    void insert(int k);
  private:
    void destroyTree(Node* n);
    void insert(int k, Node* n);

    Node* root;
};

class BreadthFirstSearch {
  BreadthFirstSearch(BinaryTree* t, int k);
  ~BreadthFirstSearch();
  Node* search(Node* n, int k);
};

class DepthFirstSearch {
  DepthFirstSearch(BinaryTree* t, int k);
  ~DepthFirstSearch();
  Node* search(Node* n, int k);
};
#endif
