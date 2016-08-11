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
 *
 *
 *
 * Contains various functions used through the project.
 */


#ifndef __list_h__
#define __list_h__
class Node {
  public:
    Node(const int& data, Node* nxt = NULL);
    ~Node();
    Node* nextNode() { return m_next; }
    void setNext(Node* nxt) { m_next = nxt; }
  private:
    int m_data;
    Node* m_next;
};

class LinkedList {
  public:
    LinkedList(Node* n = NULL);
    ~LinkedList();
    Node* at(unsigned int i);
    void push(Node* n);
    Node* pop();

  private:
    Node* m_head;
};


class Queue {
  public: 
    Queue(Node* firstNode);
    ~Queue();
    Node* pop();
    void push(Node* n);

  private:
    Node* m_first;
    Node* m_last;
};

class Stack {
  public: 
    Stack(Node* firstNode);
    ~Stack();
    Node* pop();
    void push(Node* n);
    Node* peek();

  private:
    Node* m_first;
    Node* m_last;
};

#endif // __list_h__
