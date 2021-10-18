#include <iostream>
#include <vector>

using namespace std;

class graph{
private:
    int v;

    int **adjmatrix;

public:
    graph(int V);

    void addEdge(int u, int v, bool bidir);

    void print();
};

graph::graph(int V) {
    this->v = V;
    adjmatrix = new int*[v];
    for (int i=0 ; i<v ; i++) {
        adjmatrix[i] = new int[v];
    }

    for (int i = 0 ; i < v ; i++) {
        for (int j = 0 ; j < v ; j++) {
            adjmatrix[i][j] = 0;
        }
    }
}

void graph::addEdge(int u, int v, bool bidir = true) {
    adjmatrix[u][v] = 1;

    if (bidir) {
        adjmatrix[v][u] = 1;
    }
}

void graph::print() {
    for (int i = 0 ; i < v ; i++) {
        for (int j = 0 ; j < v ; j++) {
            cout << adjmatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    graph g(4);
    g.addEdge(0, 1, false);
    g.addEdge(0, 2);
    g.addEdge(0, 3, false);
    g.addEdge(1, 3);
    g.addEdge(3, 2, false);
    g.print();
    return 0;
}