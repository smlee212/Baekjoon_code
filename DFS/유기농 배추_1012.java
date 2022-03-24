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
  
    static int t, n, m, k, cnt;
    static int[] dx = {1,-1,0,0};
    static int[] dy = {0,0,-1,1};
    static boolean[][] visited;
    static int[][] graph;
    
	public static void main(String[] args) throws IOException  {
		t = Integer.parseInt(br.readLine());
		
		while(t-->0) {
			StringTokenizer st = new StringTokenizer(br.readLine());		
			m = Integer.parseInt(st.nextToken());
			n = Integer.parseInt(st.nextToken());
			k = Integer.parseInt(st.nextToken());
			cnt = 1;
			graph = new int[n][m];
			visited = new boolean[n][m];
			
			for(int i=0;i<k;i++) {
				st = new StringTokenizer(br.readLine());
				int x = Integer.parseInt(st.nextToken());
				int y = Integer.parseInt(st.nextToken());
				
				graph[y][x] = 1;
			}
	
			for(int i=0;i<n;i++) {
				for(int j=0;j<m;j++) {
					if(graph[i][j]==1 && !visited[i][j]) {
						cnt++;
						dfs(i,j);
					}
				}
			}
			sb.append((cnt-1)+"\n");
		}
		bw.write(sb.toString());
		bw.close();
		br.close();
	}
	
	private static void dfs(int y, int x) {		
		graph[y][x] = cnt;
		visited[y][x] = true;
		
		for(int i=0;i<4;i++) {
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			if(nx<0||nx>=m||ny<0||ny>=n) continue;
			if(graph[ny][nx]==1 && !visited[ny][nx]) {
				dfs(ny,nx);
			}
		}		
	}
}
