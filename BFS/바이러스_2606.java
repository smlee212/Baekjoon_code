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
  
    static int n, m, cnt;
    static Queue<Integer> q = new LinkedList<>();
    static boolean[] visited = new boolean[100+1];
    static int[][] graph;
    
	public static void main(String[] args) throws IOException  {
		n = Integer.parseInt(br.readLine());
		m = Integer.parseInt(br.readLine());
		cnt = 0;
		
		graph = new int[n+1][n+1];
		
		for(int i=0;i<m;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int n1 = Integer.parseInt(st.nextToken());
			int n2 = Integer.parseInt(st.nextToken());
			
			graph[n1][n2] = 1;
			graph[n2][n1] = 1;
		}
		
		bfs(1);
		
		bw.write(sb.append(cnt).toString());
		bw.close();
		br.close();
	}
	
	private static void bfs(int v) {
		q.add(v);
		visited[v] = true;
		
		while(!q.isEmpty()) {
			v = q.poll();
			
			for(int i=1;i<=n;i++) {
				if(graph[v][i]==1 && !visited[i]) {
					q.add(i);
					visited[i] = true;
					cnt++;
				}
			}
		}
		
		q.clear();
	}
}