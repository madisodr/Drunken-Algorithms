/* 
* Author: Daniel R Madison
* Copyright (C) 2015
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
#include <map>
#include <string>

using namespace std;

struct node
{
    typedef pair<int, node*> cn;
    vector<cn> adj;
    string name;
    node(string s)
    {
        name = s;
    }
};

class Graph
{
    public:

        typedef pair<int, node*> cn;
        typedef map<string, node *> nmap;
        nmap work;

        void addNode(const string& name)
        {
            nmap::iterator itr = work.begin();
            itr = work.find(name);
            if(itr == work.end())
            {
                node *n = new node(name);
                work[name] = n;
                return;
            }
        }

        void addEdge(const string& from, const string& to, int cost)
        {
           node *f = (work.find(from)->second);
           node *t = (work.find(to)->second);
           pair<int, node *> edge = make_pair(cost, t);
           f->adj.push_back(edge);
        }

        void display()
        {
            nmap::iterator itr;

            for(itr = work.begin(); itr != work.end(); itr++)
            {
                cout << itr->first << " | ";
                
            }
        }
};
