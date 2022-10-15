# Topological Sort
**Definition:**
Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u v, vertex u comes before v in the ordering.
## DFS Approach
Topological Sort only exists for a Directed Acyclic Graph(DAG), 
therefore if a cycle exists in the graph then Topological Sort is not possible.<br>
Hence, we have to check for cycles in the graph.
For this purpose we keep 2 visited arrays.<br>
visited[] array keep a track of all the nodes which have been visited so far.<br>
dfsvisited[] array keeps a track of all the nodes in the current branch on recursion tree.<br>
A cycle exists in a directed graph only when a node in the current branch in the recursion tree is visited again ie.
``` 
    if(dfsvisited[neigh]){
        return true;
    }

```
when we backtrack then we mark 
```
    dfsvisited[src] = false;
```
because we are done exploring the current branch. 

Therefore if a cycle exists in the graph then topoSortDFS() function returns true and
```
return new int[0];
``` 
executes denoting that Topological Sort is not possible

otherwise,
we keep popping the top of the stack and add the popped elements to an array denoting the Topological Ordering of vertices. 

**LOGIC:**<br>
vtx->nbr<br>
Since we want a vertex(vtx) before its neighbours(nbr) in topological sort, we have no choice but to go deep into recursion and first find all the neighbours and then print vtx first and then all its neghbours.<br>
for this we require a LIFO order -> stack<br>
Therefore, in the postorder we add the particular vertex itself once we have got all the neighbours.

## Kahn's Algorithm Approach
Kahn's algorithm works on the basic principle that a vertex on which no edge is incident should come come in Topological Sort.<br>
Therefore we keep an inDegree array and use BFS to add the vertices with indegree 0 to the Topological Order.<br>
Once we add these edges we also decrease the indegree of the adjacent vertices.<br>
Then we continue with the same process.<br>
If all vertices are not visited then cycle exists 
```
if(idx != n){//cycle exists
    return new int[0];
}
```
otherwise, we return the topological sort since cycle doesn't exist.
