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
#include <queue>
#include <map>
#include "../includes/graph.h"
#include "../includes/drunk.h"


using namespace std;


Node::Node(int idx, int data) {
  m_idx = idx;
  m_data = data;
}

Node::~Node() {}

bool Node::addEdge(Node* n, int cost) {
  if(hasEdge(n))
    return false;

  m_costs.insert(pair<Node*, int>(n, cost));
  return true;
}

bool Node::remEdge(Node* n) {
  if(!hasEdge(n))
    return false;

  m_costs.erase(n);
  return true;
}

bool Node::hasEdge(Node* n) {
  if(m_costs.count(n) == 1)
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

void Graph::resetNodes() {
  for(int i = 0; i < m_nodeCount; i++) {
    m_nodes[i]->setVisted(false);
  }
}

bool Graph::addNode(Node* n) {
  if(hasNode(n))
    return false;

  m_nodes.push_back(n);
  m_nodeCount++;
  return true;
}

bool Graph::addNode(int data) {
  m_nodeCount++;
  Node* n = new Node(m_nodeCount, data);
  m_nodes.push_back(n);
  return true;
}

bool Graph::remNode(Node* n) {
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

bool Graph::DFS(Node* orig, Node* dest, int& cost) {
  if(orig == dest
      return true;

      map<Node*, int> tmp = orig->getEdges();
      auto it = tmp.begin();

      for(auto it = tmp.begin(); it != tmp.end(); it++) {
      if(it->first->visted())
      continue;

      cost += it->second;
      it->first->setVisted(true);
      if(DFS(tmp[i], dest, cost))
      return true;

      cost -= it->second;
      it->first->setVisted(false);
      }

      return false;
      }


bool Graph::BFS(Node* orig, Node* dest, int& cost) {
  if(orig == dest)
    return true;

  queue<Node*> q_node;
  auto it = q_node.begin();
  orig->setVisted(true);
  q_node.push_back(orig);

  while(!q_node.empty()) {
    Node* t = q_node.front();
    map<Node*, int> tmp = orig->getEdges();
    q_node.pop_front();
    t->setVisted(true);
    if(t == dest)
      return true;

    for(auto it = tmp.begin(); it != tmp.end(); it++) {
      if(!it->first->visted()) {
        q_node.push_back(it);
      }
    }
  }

}
