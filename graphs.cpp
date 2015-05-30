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
