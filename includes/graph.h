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

#include <vectori>
#include <map>

using namespace std;

typedef Matrix std::vector<std::vector<int> >;

class Node {
	public:


		Node(int idx, int data);
		~Node();
		bool addEdge(Node* n, int cost = 0);
		bool remEdge(Node* n);
		bool hasEdge(Node* n);
		std::vector<Node*> getEdges() { return m_costs; }
		int getIdx() { return m_idx; }
		bool visted() { return m_visted; }
		void setVisted(bool v) { m_visted = v; }
		bool operator==(Node* b) {
			return b->getIdx() == getIdx();
		}
	private:
		int m_idx;
		int m_data;
		bool m_visted;
		std::map<Node*, int> m_costs;
}



class Graph {
	public:
		Graph();
		Graph(Graph &g);
		~Graph();

		bool addNode(Node* n);
		bool addNode(int data);

		bool remNode(Node* n);
		bool remNode(int data);

	private:
		std::vector<Node*> m_nodes;
		int m_nodeCount;

};
