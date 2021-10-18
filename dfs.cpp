#include <iostream>
#include <list>

using namespace std;

class graph{
private:
    int v;

    list<int> *adj;

public:
    graph(int V);

    void addEdge(int u, int v, bool bidir);

    void dfsutil(int x, bool visited[]);

    void dfs(int start);
};

graph::graph(int V) {
    this->v = V;
    adj = new list<int>[v];
}

void graph::addEdge(int u, int v, bool bidir = true) {
    adj[u].push_back(v);

    if (bidir) {
        adj[v].push_back(u);
    }
}

void graph::dfsutil(int x, bool visited[]) {
    visited[x] = true;

    cout << x << " ";

    list<int>::iterator i;

    for (i = adj[x].begin() ; i != adj[x].end() ; i++) {
        if (!visited[*i]) {
            dfsutil(*i, visited);
        }
    }
}

void graph::dfs(int value) {
    bool *visited = new bool[v];

    for (int i=0 ; i < v ; i++) {
        visited[i] = false;
    }

    dfsutil(value, visited);
}

int main()
{
    graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 3);
    g.addEdge(3, 2);

    g.dfs(0);
    return 0;
}