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
#include <algorithm>
#include <map>
#include <string>
#include <iostream>
#include <fstream>

#include "drunk.h"

using namespace std;

class Node
{
    public:
        Node(string s){ this->label = s; }
        ~Node(){}

        void link(string n, int cost = 0) { edges[n] = cost; }
        void link(Node* n, int cost = 0) { edges[n->getLabel()] = cost; }

        void delink(string n) { edges.erase(n); }
        void delink(Node* n) { edges.erase(n->getLabel()); }

        bool isLinked(Node* n)
        {
            map<string, int>::iterator it;
            for(it = edges.begin(); it != edges.end(); ++it)
            {
                if(it->first == n->getLabel())
                    return true;
            }

            return false;
        }
        map<string, int> getEdges() { return this->edges; }
        string getLabel() { return this->label; }
    private:
        string label;
        map<string, int> edges;

};

class Graph
{

    public:
        Graph(){}
        ~Graph(){}

        void addNode(Node* n)
        {
            this->nodes.push_back(n);
        }

        void delNode(Node* n)
        {
            this->nodes.erase(remove(this->nodes.begin(), this->nodes.end(), n), this->nodes.end());
        }

        Node* getNodeByLabel(string n)
        {
            vector<Node*>::iterator it;
            for(it = nodes.begin(); it != nodes.end(); ++it)
            {
                if((*it)->getLabel() == n)
                    return *it;
            }

            return NULL;
        }


        // depth first search for a path to a goal.
        bool hasPath(Node* start, Node* goal, vector<Node*> checked)
        { 
            map<string, int>::iterator it;
            Node* curr;
            for(it = start->getEdges().begin(); it != start->getEdges().end(); ++it)
            {
                curr = getNodeByLabel(it->first);
                cout << "Traversing : " << it->first << "\n";
                if(curr->getLabel() == goal->getLabel())
                    return true;
               // else
                 //   return hasPath(curr, goal);
            }
        }

        void output()
        {
            vector<Node*>::iterator itn;
            map<string, int>::iterator ite;

            for(itn = nodes.begin(); itn != nodes.end(); ++itn)
            {
                cout << "Node Label: " << (*itn)->getLabel() << "\n";
                map<string, int> edges = (*itn)->getEdges();

                cout << "Connected Nodes => count(" << edges.size() << ")\n";
                for(ite = edges.begin(); ite != edges.end(); ++ite)
                    cout << "Node " << ite->first << " with cost " << ite->second << "\n";

                cout << "\n";
            }
        }

    private:
        vector<Node*> nodes;
};

class Dijkstras
{ 

};

class AStar
{
    public:
        AStar(Graph* g, Node* start, Node* goal)
        { 
        }

};

class BFS
{ 
};

class DFS
{ 
};

int main(int argc, char*argv[])
{
 
    size_t pos;
    string token, line, s_cost, name;
    int cost;

    ifstream inFile ("data/graph1.txt");

    // create a new graph
    Graph* graph = new Graph();

    if(inFile.is_open()) // did we open the file?
    {
        while(getline(inFile, line))
        {
            cost = 0;

            // ignore lines that are comments or blank
            if((line.compare(0,2,"##") == 0) || (line.length() == 0))
                continue;
            
            // grab the node's label and create the node.
            string nodeLabel = line.substr(0, line.find(NODE_DELIM));
            Node* node = new Node(trim(nodeLabel));
            
            // Grab the rest of the line. These are the edges. 
            string nodeEdges = line.substr(line.find(NODE_DELIM)+1, line.length()-1);

            // if its an unconnected node then we dont need to do anything more.
            if(nodeEdges.length() == 0)
            {
                graph->addNode(node);
                continue;
            }

            // split the rest of the line and extract al the edges
            while((pos = nodeEdges.find(NODE_LINK_DELIM)) != string::npos)
            {
                token = nodeEdges.substr(0, pos);

                name = token.substr(0, token.find("("));
                s_cost = token.substr(token.find("(") + 1, token.find(")") - token.find("(") - 1);
                cost = atoi( trim(s_cost).c_str());

                node->link(trim(name), cost);
                nodeEdges.erase(0, pos + 1);
            }

            // the while loop stops at the last element but we still need to
            // add it to the node. 
            name = nodeEdges.substr(0, nodeEdges.find("("));
            s_cost = nodeEdges.substr(nodeEdges.find("(") + 1, nodeEdges.find(")") - nodeEdges.find("(") - 1);
            cost = atoi(trim(s_cost).c_str());
            node->link(trim(name), cost);

            // add our new node to the graph
            graph->addNode(node);
        }

        inFile.close();
    }
    else 
        cout << "ERROR: Unable to open data file.\n";

    graph->output();

    if(graph->hasPath(graph->getNodeByLabel("a"), graph->getNodeByLabel("g")))
        cout << "Has path.\n";
    else
        cout << "No path found.\n";

    return 0;
}
