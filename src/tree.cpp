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
#include "../includes/tree.h"

using namespace std;


Node::Node(int id, int parent, string name) {
  m_id = id;
  m_parent = parent;
  m_name = name;
}

Node::~Node() {
  for(size_t i = 0; i < m_children.size(); i++) {
    delete m_children[i];
  }
}

bool Node::addChild(Node* n) {


  if(n->getParent() == m_id) {
    cout << "Adding " << n->getName() << " to " << getName() << "\n";
    m_children.push_back(n);
    return true;
  } else {
    for(size_t i = 0; i < m_children.size(); i++) {
      m_children[i]->addChild(n);
    }
  }

  return false;
}

bool Node::remChild(Node* n) {
  int idx = -1;
  for(size_t i = 0; i < m_children.size(); i++) {
    if(m_children[i] == n) {
      idx = i;
      break;
    }
  }

  if(idx == -1)
    return false;
    
  m_children.erase(m_children.begin() + idx);
  return true;

}

Graph::Graph() {
  root = new Node(0, 0, "Root");
}

Graph::~Graph() {
  delete root;
}

bool Graph::addNode(Node* n) {
  return root->addChild(n);
}

bool Graph::remNode(Node* n) {
  return root->remChild(n);
}
