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

#ifndef __drunk_trie_h__
#define __drunk_trie_h__

#include <vector>

class Node {
	public:
		Node();
		~Node();
		char getContent() { return m_content; }
		void setContent(char c) { m_content = c; }

		bool wordMarker() { return m_marker; }
		void setWordMarker() {m_marker = true;}
		Node* findChild(char c);
		void appendChild(Node* child) { m_children.push_back(child); }
		std::vector<Node*> children() { return m_children; }

	private:
		char m_content;
		bool m_marker;
		std::vector<Node*> m_children;
};


class Trie { 
	public:
		Trie();
		~Trie();
		void addWord(std::string s);
		bool searchWord(std::string s);
	private:
		Node* root;
};

#endif //__drunk_trie_h__
