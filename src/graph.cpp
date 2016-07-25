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

bool Node::addEdge(Node* n) {
	if(hasEdge(n))
		return false;

	m_edges.push_back(n);
	return true;
}

bool Node::remEdge(Node* n) {
	if(!hasEdge(n))
		return false;

	auto it = std::find(m_edges.begin(), m_edges.end(), n);
	if(it != m_edges.end()) {
		using std::swap;
		swap(*it, m_edges.back());
		m_edges.pop_back();
		return true
	}

	return false;
}

bool Node::hasEdge(Node* n) {
	auto it = std::find(m_edges.begin(), m_edges.end(), n);

	if(it != m_edges.end())
		return true;
	else
		return false;
}

Graph::Graph() {
	m_nodeCount = 0;
}

Graph::~Graph() {
	for(int i = 0; i < m_nodes; i++) {
		delete m_nodes[i];
	}

	m_nodeCount = 0;
}

bool addNode(Node* n) {
	if(hasNode(n))
		return false;

	m_nodes.push_back(n);
	m_nodeCount++;
	return true;
}

bool addNode(int data) {
	m_nodeCount++;
	Node* n = new Node(m_nodeCount, data);
	m_nodes.push_back(n);
	return true;
}

bool remNode(Node* n) {
	if(!hasNode(n)) 
		return false;

	auto it = find::(m_nodes.begin(), m_nodes.end(), n);
	if(it != m_edges.end()) {
		using std::swap;
		swap(*it, m_edges.back());
		m_edges.pop_back();
		return true;
	}

	return false;
}
