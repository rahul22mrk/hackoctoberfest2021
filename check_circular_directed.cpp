#include <bits/stdc++.h>

using namespace std;

class graph {
    int v;

    list<int> *adj;

    bool isCyclicUtil(int i, bool vector[], bool recur[]);

public:
    graph(int V);

    void addNode(int u, int v);

    bool isCyclic();
};

graph::graph(int V) {
    this->v = V;
    adj = new list<int>[v];
}

void graph::addNode(int u, int v) {
    adj[u].push_back(v);
}

bool graph::isCyclicUtil(int i, bool visited[], bool recur[]) {
    if (!visited[i]) {
        visited[i] = true;
        recur[i] = true;

        list<int>::iterator j;
        for (j = adj[i].begin() ; j != adj[i].end() ; j++) {
            if (!visited[*j] && isCyclicUtil(*j, visited, recur)) {
                return true;
            }
            else if (recur[*j]) {
                return true;
            }
        }

        recur[i] = false;
        return false;
    }
}

bool graph::isCyclic() {
    bool *visited = new bool[v];
    bool *recur = new bool[v];

    for (int i=0 ; i<v ; i++) {
        visited[i] = false;
        recur[i] = false;
    }

    for (int j=0 ; j<v ; j++) {
        if (isCyclicUtil(j, visited, recur)) {
            return true;
        }
    }

    return false;
}

int main()
{
    graph g(4);
    g.addNode(0, 1);
    g.addNode(0, 3);
    g.addNode(1, 3);
    g.addNode(2, 0);
    g.addNode(2, 3);


    if(g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}
