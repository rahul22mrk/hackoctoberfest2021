//Topological sort using DFS
import java.util.*;

//Cycle detection is done using two visited arrays visited and dfsvisited.
//Topological sort exists only in a Directed Acyclic Graph(DAG)
//Therefore if a cycle exists then topological sort doesn't exist
public class TopologicalSortDFS {
    //topological sort is nothing but DFS with Stack filling in postorder

    //returns true if cycle exits otherwise returns false
    private static boolean topoSortDFS(LinkedList<Integer> adj[], ArrayDeque<Integer> st, boolean visited[], boolean dfsvisited[], int src){
               
        visited[src] = true;
        dfsvisited[src] = true;
        
        for(int neigh: adj[src]){
            if(!visited[neigh]){
                if(topoSortDFS(adj, st, visited, dfsvisited, neigh)) return true;
            }else if(dfsvisited[neigh]){
                return true;
            }
        }
        
        dfsvisited[src] = false;
        
        //add to stack in postorder
        
        //LOGIC:        
        //vtx->nbr
        //since we want a vertex(vtx) before its neighbours(nbr) in topological sort 
        // we have no choice but to go deep into recursion and first find all the neighbours and then print vtx first and then all its neghbours
        // for this we require a LIFO order -> stack
        //therefore in the postorder we add the particular vertex itself once we have got all the neighbours
        st.push(src);
        return false;
    }
    public static int[] topologicalSort(LinkedList<Integer> adj[], int n){
        ArrayDeque<Integer> st = new ArrayDeque<>();
        boolean[] visited = new boolean[n], dfsvisited = new boolean[n];
        
        for(int vtx=0; vtx<n; vtx++){
            if(!visited[vtx]){
                if(topoSortDFS(adj, st, visited, dfsvisited, vtx)){
                    return new int[0];
                }
            }
        }
                
        int ans[] = new int[st.size()];
        int idx=0;
        while(!st.isEmpty()){
            ans[idx++] = st.pop();
        }
        return ans;
    }
}
