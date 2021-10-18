#include <iostream>
#include <list>

using namespace std;


class graph {
private:
    int V;

    list<int> *adjlist;

public:
    graph(int v);

    void addEdge(int u, int v, bool bidir);

    void print();
};

graph::graph(int v) {
    this->V = v;
    adjlist = new list<int>[V];
}

void graph::addEdge(int u, int v, bool bidir = true) {
    adjlist[u].push_back(v);

    if (bidir) {
        adjlist[v].push_back(u);
    }
}

void graph::print() {
    for (int i=0 ; i<V ; i++) {
        cout << i << " -> ";
        for (int node:adjlist[i]) {
            cout << "  ";
            cout << node << ", ";
        }
        cout << endl;
    }
}

int main()
{
    graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 3);
    g.addEdge(3, 2);
    g.print();

    return 0;
}
