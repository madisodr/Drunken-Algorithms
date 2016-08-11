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

#include "../includes/trie.h"
#include <iostream>
#include <vector>

Node* Node::findChild(char c) {
  for(int i = 0; i < m_children.size(); i++) {
    Node* tmp = m_children[i];
    if(tmp->content() == c)
      return tmp;
  }

  return null;
}

Trie::Trie() {
  root = new Node();
}

Trie::~Trie() {

}

void Trie::addWord(std::string s) {
  Node* curr = root;
  if(s.length() == 0) {
    curr->setWordMarker();
    return;
  }

  for(int i = 0; i < s.length(); i++) {
    Node* child = curr->findChild(s[i]);
    if(child != NULL) {
      curr = child;
    } else {
      Node* tmp = new Node();
      tmp->setContent(s[i]);
      curr->appendChild(tmp);
      curr = tmp;
    }

    if(i == s.length() - 1)
      curr->setWordMarker();
  }
}

bool Trie::searchWord(std::string s) {
  Node* curr = root;

  while(curr != NULL) {
    for(int i = 0; i < s.length(); i++) {
      Node* tmp = curr->findChild(s[i]);
      if(tmp == NULL)
        return false;
      curr = tmp;
    }

    if(curr->wordMarker())
      return true;
    else
      return false;
  }

  return false;
}
