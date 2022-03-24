import java.util.*;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException; 

class Main {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringBuilder sb = new StringBuilder();
    
    static int n, m;
    static int[][] graph;
    static boolean[] visited = new boolean[1001];
    static Queue<Integer> q = new LinkedList<>();
   
    private static void dfs(int v) {
    	visited[v] = true;
    	sb.append(v+" ");
    	
    	for(int i=1;i<=n;i++) {
    		if(graph[v][i]==1 && !visited[i]) {
    			dfs(i);
    		}
    	}
    }
    
    private static void bfs(int v) {
    	q.add(v);
    	visited[v] = true;
    	
    	while(!q.isEmpty()) {
    		v = q.poll();
    		sb.append(v+" ");
    		
    		for(int i=1;i<=n;i++) {
    			if(graph[v][i]==1 && !visited[i]) {
    				q.add(i);
    				visited[i] = true;
    			}
    		}
    	}
    	q.clear();
    }
    
	public static void main(String[] args) throws IOException  {
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		int v = Integer.parseInt(st.nextToken());
		
		graph = new int[n+1][n+1];
		
		for(int i=0;i<m;i++) {
			st = new StringTokenizer(br.readLine());
			int node1 = Integer.parseInt(st.nextToken());
			int node2 = Integer.parseInt(st.nextToken());
			
			graph[node1][node2] = 1;
			graph[node2][node1] = 1;
		}
		
		dfs(v);
		sb.append("\n");
		Arrays.fill(visited, false);
		
		bfs(v);
		
		bw.write(sb.toString());
		bw.close();
		br.close();
	}
}