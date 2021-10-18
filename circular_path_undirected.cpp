#include <bits/stdc++.h>

using namespace std;

class graph {
    int v;

    list<int> *adj;

    bool isCyclicUtil(int x, bool visited[], int parent);

public:
    graph(int V);

    void addEdge(int u, int v);

    bool isCyclic();
};

graph::graph(int V) {
	this->v = V;
	adj = new list<int>[v];
}

void graph::addEdge(int u, int v) {
    adj[u].push_back(v);
	adj[v].push_back(u);
}

bool graph::isCyclicUtil(int x, bool visited[], int parent) {
	visited[x] = true;

	list<int>::iterator i;

	for (i = adj[x].begin(); i != adj[x].end(); i++) {
		if (!visited[*i] && isCyclicUtil(*i, visited, x)) {
			return true;
		}
		else if(*i != parent) {
			return true;
		}
	}
	return false;
}

bool graph::isCyclic() {
	bool *visited = new bool[v];

	for (int i = 0; i < v; i++) {
		visited[i] = false;
	}

	for (int i = 0; i < v; i++) {
		if (!visited[i] && isCyclicUtil(i, visited, -1)) {
			return true;
		}
	}

	return false;
}

int main()
{
	graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 3);


    g.isCyclic() ?
       cout << "Graph contains cycle\n" :
       cout << "Graph doesn't contain cycle\n";

	return 0;
}