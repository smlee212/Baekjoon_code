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
  
    static int n,m;
    static int[][] graph;
    static boolean[] visited;
    
	public static void main(String[] args) throws IOException  {
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		graph = new int[n+1][n+1];
		visited = new boolean[n+1];
		
		for(int i=0;i<m;i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			
			graph[a][b] = 1;
			graph[b][a] = 1;
		}
		
		int cnt = 0;
		for(int i=1;i<=n;i++) {
			if(!visited[i]) {
				dfs(i);
				cnt++;
			}
		}
		
		bw.write(sb.append(cnt).toString());
		bw.close();
		br.close();
	}
	
	public static void dfs(int x) {
		visited[x] = true;
		
		for(int i=1;i<=n;i++) {
			if(graph[x][i]==1 && !visited[i]) {
				dfs(i);
			}
		}
	}
}