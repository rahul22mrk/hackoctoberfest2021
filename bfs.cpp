#include <iostream>
#include <list>

using namespace std;

class graph {
private:
    int v;

    list<int> *adj;
public:
    graph(int V);

    void addEdge(int u, int v, bool bidir);

    void bfs(int value);
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

void graph::bfs(int value) {
    bool *visited = new bool[v];

    for (int i = 0 ; i < v ; i++) {
        visited[i] = false;
    }

    list<int> queue;
    visited[value] = true;
    queue.push_back(value);

    list<int>::iterator i;

    while (!queue.empty())
    {
        value = queue.front();
        cout << value << " ";
        queue.pop_front();

        for (i = adj[value].begin() ; i != adj[value].end() ; i++) {
            if (!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
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

    g.bfs(0);
    return 0;
}