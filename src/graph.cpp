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

#include <iostream>
#include <vector>
#include "../includes/graph.h"
#include "../includes/drunk.h"

using namespace std;

Node::Node(int idx, int data) {
	m_idx = idx;
	m_data = data;
}

Node::~Node() {}

AdjacencyMatrix::AdjacencyMatrix() {
	// empty constructor	
}

AdjacencyMatrix::AdjacencyMatrix(int n) {
	m_matrix.reserve(n);
	for(int i = 0; i < n; i++) {
		vector<Node*> tmp (n);
		m_matrix[i] = tmp;
	}
}

AdjacencyMatrix::~AdjacencyMatrix() {
	for(uint i = 0; i < m_matrix.size(); i++) {
		for(uint j = 0; j < m_matrix[i].size(); j++) {
			delete m_matrix[i][j];
		}
	}
}

AdjacencyMatrix::addNode(Node* n) {
	
}

class Graph {
    public:
        // Construct a new graph with number v verticies. 
        Graph(int _v) { 
            this->v = _v;
            adj = new list<int>[v];
        }
        void addEdge(int v, int w) {
            adj[v].push_back(w); // add w to v's list
        }

        void BFS(int s) {
            // Mark a set of vertices as not visted
            bool* checked = new bool[];
            for(int i = 0; i < v; i++) 
                checked[i] = false;

            list<int> queue;
            checked[s] = true;
            queue.push_back(s);
            list<int>::iterator i;
            while(!queue.empty()) {
                s = queue.front();
                cont << s << " ";
                queue.pop_front();

                for(i = adj[s].begin(); i != adj[s].end(); ++i) {
                    if(!checked[*i]) {
                        checked[*i] = true;
                        queue.push_back(*i);
                    }
                }
            }
        }


        // Main method for depth first search traversal
        void DFS(int s) {
            bool* checked = new bool[];
            for(int i = 0; i < v; i++)
                checked[i] = false;

            DFS(v, checked);

        }

        // The depth first recursion
        void DFS(int s, bool checked[]){
            checked[v] = true;
            cout << v << " ";
            
            list<int>::iterator i;
            for(i adj[v].begin(); i != adj[v].end(); i++) {
                if(!checked[*i])
                    DFS(v, checked);
            }
        }

        void AStar() {}
        void Dijkstras() {}
    private:
        int v;
        list<int> *adj;
};

int main() {
    Graph graph(4);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(2, 3);
    graph.addEdge(3, 3);

    cout << "Breadth First Search\n";
    graph.BFS();
    cout << "Depth First Search\n";
    graph.DFS();
}
