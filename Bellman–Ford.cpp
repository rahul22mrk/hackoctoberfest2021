#include <bits/stdc++.h>

using namespace std;

struct Edge {
	int source;
	int dest;
	int weight;
};

struct Graph {
	int v, e;

	struct Edge *Edge;
};

struct Graph* createGraph (int v, int e) {
	struct Graph* graph = new Graph;
	graph->v = v;
	graph->e = e;
	graph->Edge = new Edge[e];
	return graph;
}

void printDist(int dest[], int n) {
	cout << "\nShortest paths are: \n";
	cout << "\nvertex \t\t Distance\n";
	for (int i = 0; i < n; i++) {
		cout << i << " \t\t " << dest[i] << "\n";
	}
	return;
}

void BellmanFord (struct Graph* graph, int Source) {
	int V = graph->v;
	int E = graph->e;
	int dist[V];

	for (int i = 0; i < V; i++) {
		dist[i] = INT_MAX;
	}

	dist[0] = 0;

	for (int i = 0; i < V-1; i++) {
		for (int j = 0; j < E; j++) {
			int u = graph->Edge[j].source;
			int v = graph->Edge[j].dest;
			int weight = graph->Edge[j].weight;
			if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
				dist[v] = weight + dist[u];
			}
		}
	}

	for (int i = 0; i < E; i++) {
		int u = graph->Edge[i].source;
		int v = graph->Edge[i].dest;
		int weight = graph->Edge[i].weight;
		if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
			cout << "\n**Graph contains negitive cycle**\n";
			return;
		}
	}

	printDist(dist, V);

	return;
}

int main()
{
	int V = 5; // Number of vertices in graph
    int E = 8; // Number of edges in graph
    struct Graph* graph = createGraph(V, E);
  
    // add edge 0-1 (or A-B in above figure)
    graph->Edge[0].source = 0;
    graph->Edge[0].dest = 1;
    graph->Edge[0].weight = -1;
  
    // add edge 0-2 (or A-C in above figure)
    graph->Edge[1].source = 0;
    graph->Edge[1].dest = 2;
    graph->Edge[1].weight = 4;
  
    // add edge 1-2 (or B-C in above figure)
    graph->Edge[2].source = 1;
    graph->Edge[2].dest = 2;
    graph->Edge[2].weight = 3;
  
    // add edge 1-3 (or B-D in above figure)
    graph->Edge[3].source = 1;
    graph->Edge[3].dest = 3;
    graph->Edge[3].weight = 2;
  
    // add edge 1-4 (or A-E in above figure)
    graph->Edge[4].source = 1;
    graph->Edge[4].dest = 4;
    graph->Edge[4].weight = 2;
  
    // add edge 3-2 (or D-C in above figure)
    graph->Edge[5].source = 3;
    graph->Edge[5].dest = 2;
    graph->Edge[5].weight = 5;
  
    // add edge 3-1 (or D-B in above figure)
    graph->Edge[6].source = 3;
    graph->Edge[6].dest = 1;
    graph->Edge[6].weight = 1;
  
    // add edge 4-3 (or E-D in above figure)
    graph->Edge[7].source = 4;
    graph->Edge[7].dest = 3;
    graph->Edge[7].weight = -3;
  
    BellmanFord(graph, 0);

	return 0;
}