import java.util.*;

public class TopologicalSortKahns {
    public static int[] topologicalSort(LinkedList<Integer> adj[], int n){
        //Array to store the topological sort
        int[] TopoSort = new int[n];
        int inDegree[] = new int[n];
        for(int i=0; i<n; i++){
            for(int nbr: adj[i]){
                //edge: i->nbr 
                inDegree[nbr]++;
            }
        }

        Queue<Integer> q = new LinkedList<Integer>();
        for(int i=0; i<n; i++){
            if(inDegree[i] == 0){
                q.add(i);
            }
        }
        
        int rem;
        int idx = 0;
        while(!q.isEmpty()){
            rem = q.remove();
            TopoSort[idx++] = rem;
            for(int neigh: adj[rem]){
                inDegree[neigh]--;
                if(inDegree[neigh] == 0){
                    q.add(neigh);
                }
            }
        }
        
        if(idx != n){//cycle exists
            return new int[0];
        }
        return TopoSort;
    }
}
