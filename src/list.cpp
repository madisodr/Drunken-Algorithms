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

Node::Node(const int& data, Node* nxt) {
	m_data = data;
	m_next = nxt;
}

Node::~Node() {
	if(m_next != NULL)
		delete m_next;
}

List::List(Node* firstNode) {
	this->m_first = firstNode;
}

List::~List() {
	delete m_first;
}

Queue::Queue(Node* firstNode) : List(firstNode) {
	m_last = firstNode;
}

Queue::~Queue() {
	delete m_first;
}

void Queue::push(Node* n) {
	m_last->setNext(n);
	m_last = n;
}

Node* Queue::pop() {
	Node* r = m_first;
	m_first = m_first->nextNode();
	return r;
}

Stack::Stack(Node* firstNode) : List(firstNode) {  
	m_last = firstNode;
}

Stack::~Stack() {
	delete m_first;
}

void Stack::push(Node* n) {
	m_last->setNext(n);
	n->setPrev(m_last);
	m_last = n;
}

Node* Stack::pop() {
	Node* r = m_last;
	m_last = m_last->prevNode();
	m_last->setNext(NULL);

	return r;
}
