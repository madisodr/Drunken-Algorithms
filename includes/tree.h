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

#ifndef __drunk_tree_h__
#define __drunk_tree_h__

#include <vector>
#include <string>

class Node {
  public:
    Node(int id, int parent, std::string name);
    ~Node();


    int getId() { return m_id; }
    int getParent() { return m_parent; }
    std::string getName() { return m_name; }

    bool addChild(Node* n);
    bool remChild(Node* n);
  private:
    int m_id;
    int m_parent;
    std::string m_name;
    std::vector<Node*> m_children;
};

class Graph {

  public:
    Graph();
    ~Graph();
    Node* getRoot() { return root; }
    bool addNode(Node* n);
    bool remNode(Node* n);
  private:
    Node* root;
};

#endif
