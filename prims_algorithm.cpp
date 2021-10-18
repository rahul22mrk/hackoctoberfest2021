#include <bits/stdc++.h>
using namespace std;

#define V 5

int minKey(int array[], bool mstVisited[]) {
    int min = INT_MAX;
    int min_index;

    for (int i = 0; i < V; i++) {
        if (mstVisited[i] == false && array[i] < min) {
            min = array[i];
            min_index = i;
        }
    }

    return min_index;
}

void printMst(int parent[], int graph[V][V]) {
    cout<<"Edge \tWeight\n"; 
    for (int i = 1; i < V; i++) 
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";
}

void primsMST(int graph[V][V]) {
    int parent[V];
    int key[V];
    bool mstVisited[V];

    for (int i = 0; i < V; i++) {
        mstVisited[i] = false;
        key[i] = INT_MAX;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V-1; count++) {
        int min = minKey(key, mstVisited);

        mstVisited[min] = true;

        for (int i = 0; i < V; i++) {
            if (graph[min][i] && mstVisited[i] == false && graph[min][i] < key[i]) {
                parent[i] = min;
                key[i] = graph[min][i];
            }
        }
    }

    printMst(parent, graph);
}

int main()
{
    int graph[V][V] = { { 0, 2, 0, 6, 0 }, 
                        { 2, 0, 3, 8, 5 }, 
                        { 0, 3, 0, 0, 7 }, 
                        { 6, 8, 0, 0, 9 }, 
                        { 0, 5, 7, 9, 0 } };
                    
    primsMST(graph);

    return 0;
}