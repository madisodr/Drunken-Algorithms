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
#include <vector>

using namespace std;

TrieNode::TrieNode() {}

TrieNode::~TrieNode() {
  for(auto const& it : m_children)
    delete it;
}

TrieNode* TrieNode::findChild(char c) {
  for(auto const& it : m_children) {
    if(it->getContent() == c)
      return it;
  }

  return NULL;
}

Trie::Trie() {
  root = new TrieNode();
}

Trie::~Trie() {
  delete root;
}

void Trie::addWord(string s) {
  TrieNode* curr = root;
  if(s.length() == 0) {
    curr->setWordMarker();
    return;
  }

  for(int i = 0; i < s.length(); i++) {
    TrieNode* child = curr->findChild(s[i]);
    if(child != NULL) {
      curr = child;
    } else {
      TrieNode* tmp = new TrieNode();
      tmp->setContent(s[i]);
      curr->appendChild(tmp);
      curr = tmp;
    }

    if(i == s.length() - 1)
      curr->setWordMarker();
  }
}

bool Trie::searchWord(string s) {
  TrieNode* curr = root;

  while(curr != NULL) {
    for(int i = 0; i < s.length(); i++) {
      TrieNode* tmp = curr->findChild(s[i]);
      if(tmp == NULL)
        return false;
      curr = tmp;
    }

    if(curr->getWordMarker())
      return true;
    else
      return false;
  }

  return false;
}
