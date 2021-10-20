import java.io.*;
import java.util.*;


/* 
Problem Link : https://www.hackerrank.com/challenges/journey-to-the-moon/problem
Journey to the Moon Solution Hackerrank
*/

class Result {
  
  
    public long dfs(ArrayList<Integer>[] graph, boolean[] vis, int src) {
       
        vis[src] = true;
        long count = 0;
       
        for (Integer e : graph[src]) {
           
            if (!vis[e])
                count += dfs(graph, vis, e);
        }

        return count + 1;
    }

    public long journeyToMoon(ArrayList<Integer>[] graph, int N) {
        boolean[] vis = new boolean[N];
       
        ArrayList<Long> population = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            if (!vis[i]) {
                population.add(dfs(graph, vis, i));
            }
        }

        long ans = 0;
        long ssf = 0;    // sum so far
        
        for(int i=0;i<population.size()-1;i++)
        {
            for(int j=i+1;j<population.size();j++)
            {
                ans = population.get(i)*population.get(j);
                ssf+=ans;
            }
        }
 

        return ssf;
    }

}

public class journeyToMoon {
    public static void main(String[] args) throws IOException {
        Scanner scn = new Scanner(System.in);
        int N = scn.nextInt();
        int Edges = scn.nextInt();
        ArrayList<Integer>[] graph = new ArrayList[N];
        
        for (int i = 0; i < N; i++)
            graph[i] = new ArrayList<>();


        for (int i = 0; i < Edges; i++) {
            int a = scn.nextInt(), b = scn.nextInt();
            graph[a].add(b);
            graph[b].add(a);
        }

        Result obj = new Result();
        long ans = obj.journeyToMoon(graph, N);
        System.out.println(ans);

    }
}
