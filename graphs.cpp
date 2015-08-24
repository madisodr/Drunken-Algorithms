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
#include <gtk/gtk.h>

#include "drunk.h"

using namespace std;

class HTML_Output
{
}

typedef vector<Node*> node_vector;
typedef node_vector::iterator node_itr;

typedef map<Node*, int> edge_vector;
typedef edge_vector::iterator edge_itr;

class Node
{
    public:
        Node(int /*id*/, string s)
        {
            this->label = s;
        }

        ~Node(){}

        link(Node* n, int cost = 0) 
        { 
            edges[n] = cost; 
        }

        delink(Node* n) 
        { 
            edges.erase(n);
        }

        map<Node*, int> getEdges()
        {
            return this->edges;
        }

        string getLabel()
        {
            return this->label;
        }
        
    private:
        string label;
        map<Node*, int> edges;

}
class Graph
{

    public:
        Graph(){}
        ~Graph(){}

        addNode(Node* n)
        {
            this->nodes.push_back(n);
        }

        delNode(Node* n)
        {
            nodes.erase(std::remove(nodes.begin(), nodes.end(), n), nodes.end);
        }

        void output()
        {
            for(node_itr itn = nodes.begin(); itn != nodes.end(); ++itn)
            {
                cout << itn->getLabel() << "\n";
                map<Node*, int> edges = itn->getEdges();

                for(edge_itr ite = edges.begin(); ite != edges.end(); ++ite)
                {
                    cout << ite->first->getLabel() << " => " << ite->second << "\n";
                }
            }
        }

    private:
        vector<Node*> nodes;
};

int main(int argc, char*argv[])
{

}
