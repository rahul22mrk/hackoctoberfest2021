#include <iostream>
#include <stack>
#include <list>

using namespace std;

class graph {
private:
    int v;

    list<int> *adj;

    void topologicalSortUtil(int i, bool visited[], stack<int>& s);
    
public:
    graph(int V);

    void addNode(int u, int v);

    void topologicalSort();
};

graph::graph(int V) {
    this->v = V;
    adj = new list<int>[v];
}

void graph::addNode(int u, int v) {
    adj[u].push_back(v);
}

void graph::topologicalSortUtil(int i, bool visited[], stack<int>& s) {
    visited[i] = true;

    list<int>::iterator index;
    for (index = adj[i].begin() ; index != adj[i].end() ; index++) {
        if(!visited[*index]) {
            topologicalSortUtil(*index, visited, s);
        }
    }

    s.push(i);
}

void graph::topologicalSort() {
    stack<int> s;

    bool* visited = new bool[v];
    for (int i=0 ; i<v ; i++) {
        visited[i] = false;
    }

    for (int i=0 ; i<v ; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, visited, s);
        }
    }

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}

int main()
{
    graph g(6);
    g.addNode(5, 2);
    g.addNode(5, 0);
    g.addNode(4, 0);
    g.addNode(4, 1);
    g.addNode(2, 3);
    g.addNode(3, 1);

    cout << "Following is a Topological Sort of the given graph \n";
    g.topologicalSort();

    getchar();
    
    return 0;
}
