#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int source;
    int dest;
    int weight;
};

bool myComp(Edge a, Edge b) {
    return a.weight < b.weight;
}

int findParent(int *parent, int v) {
    if (parent[v] == v) {
        return v;
    }

    return findParent(parent, parent[v]);
}

void kruskals(Edge *input, int n, int E) {
    sort(input, input + E, myComp);

    Edge *output = new Edge[n - 1];
    int *parent = new int[n];

    for (int j = 0; j < n; j++) {
        parent[j] = j;
    }

    int count = 0;
    int i = 0;

    while (count < n-1) {
        Edge currentEdge = input[i];

        int sourceParent = findParent(parent, currentEdge.source);
        int destParent = findParent(parent, currentEdge.dest);

        if (sourceParent != destParent) {
            output[count] = input[i];
            count++;
            parent[sourceParent] = destParent;
        }
        i++;
    }

    for (int j = 0; j < n-1; j++) {
        if (output[j].source < output[j].dest) {
            cout << output[j].source << "  " << output[j].dest
                 << "  " << output[j].weight << "\n";
        }
        else {
            cout << output[j].dest << "  " << output[j].source
                 << "  " << output[j].weight << "\n";
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements to be entered: ";
    cin >> n;

    int E;
    cout << "Enter the number of Edges: ";
    cin >> E;

    cout << "\nEnter the data: \n";
    Edge *input = new Edge[E];
    for (int i = 0;  i < E; i++) {
        int s, d, w;
        cin >> s >> d >> w;
        input[i].source = s;
        input[i].dest = d;
        input[i].weight = w;
    }

    cout << "\nMinimum spanning tree is: \n";
    kruskals(input, n, E);

    return 0;
}