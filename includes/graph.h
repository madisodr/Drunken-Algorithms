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

#include <vector>

using namespace std;

typedef Matrix std::vector<std::vector<Node*> >;

class Node {
	public:
		Node(int idx, int data);
		~Node();

		int m_idx;
		int m_data;
};

class AdjacencyMatrix {
	public:
		AdjacencyMatrix();
		AdjacencyMatrix(int n);
		~AdjacencyMatrix();
		bool addNode(Node* n);
		bool removeNode(Node* n);
		bool removeNode(int idx);
		bool addEdge(Node* a, Node* b);
		bool removeEdge(Node* a, Node* b);
		Node* getNode(int idx);
	private:
		Matrix m_matrix;
};
