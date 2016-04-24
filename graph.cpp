#include <iostream>
#include <list>

using namespace std;

class Graph {
    public:
        // Construct a new graph with number v verticies. 
        Graph(int _v) { 
            this->v = _v;
            adj = new list<int>[v];
        }
        void addEdge(int v, int w) {
            adj[v].push_back(w); // add w to v's list
        }

        void BFS(int s) {
            // Mark a set of vertices as not visted
            bool* checked = new bool[];
            for(int i = 0; i < v; i++) 
                checked[i] = false;

            list<int> queue;
            checked[s] = true;
            queue.push_back(s);
            list<int>::iterator i;
            while(!queue.empty()) {
                s = queue.front();
                cont << s << " ";
                queue.pop_front();

                for(i = adj[s].begin(); i != adj[s].end(); ++i) {
                    if(!checked[*i]) {
                        checked[*i] = true;
                        queue.push_back(*i);
                    }
                }
            }
        }


        // Main method for depth first search traversal
        void DFS(int s) {
            bool* checked = new bool[];
            for(int i = 0; i < v; i++)
                checked[i] = false;

            DFS(v, checked);

        }

        // The depth first recursion
        void DFS(int s, bool checked[]){
            checked[v] = true;
            cout << v << " ";
            
            list<int>::iterator i;
            for(i adj[v].begin(); i != adj[v].end(); i++) {
                if(!checked[*i])
                    DFS(v, checked);
            }
        }

        void AStar() {}
        void Dijkstras() {}
    private:
        int v;
        list<int> *adj;
};

int main() {
    Graph graph(4);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(2, 3);
    graph.addEdge(3, 3);

    cout << "Breadth First Search\n";
    graph.BFS();
    cout << "Depth First Search\n";
    graph.DFS();
}
