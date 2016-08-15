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

namespace search {
  Node* BFS(Graph* g, int k) {
    
  }

  Node* BFS(Node* n, int k) {
    
  } 
  Node* DFS(Graph* g, int id) {
    if(id == 0) 
      return g->getRoot();
    else
      return DFS(g, id);
  }

  Node* DFS(Node* n, int id) {
    for(size_t i = 0; i < m_children.size(); i++) {
      if(m_children[i]->getId() == id)
        return m_children[i];
      else {
        Node* ret = DFS(m_children[i], id);
        if(ret->getId() == id)
          return ret;
      }
    }

    return NULL;
  }
}
#endif
