#include <bits/stdc++.h>
using namespace std;

#define V 9

int minDistance(int dist[], bool visited[]) {
    int min = INT_MAX;
    int minIndex;

    for (int v=0 ; v<V ; v++) {
        if (!visited[v] && dist[v] < min)
            min = dist[v], minIndex = v;
    }

    return minIndex;
}

void printDist(int dist[]) {
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstras(int graph[][V], int src) {
    int dist[V];
    bool visited[V];

    for (int v=0 ; v<V ; v++)
        dist[v] = INT_MAX, visited[v] = false;

    dist[src] = 0;

    for (int count=0 ; count<V-1 ; count++) {
        int min = minDistance(dist, visited);

        visited[min] = true;

        for (int v=0 ; v<V ; v++) {
            if (!visited[v] && graph[min][v] && dist[min] != INT_MAX 
                    && dist[min] + graph[min][v] < dist[v])
                dist[v] = dist[min] + graph[min][v];
        }
    }

    printDist(dist);
}

int main()
{
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
  
    dijkstras(graph, 0);
    return 0;
}