import java.util.*;
import java.awt.Point;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException; 

class Main {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringBuilder sb = new StringBuilder();
  
    static int n, max_h;
    static int[][] graph;
    static int[] dx = {1,0,-1,0};
    static int[] dy = {0,1,0,-1};
    static boolean[][] visited;
    
	public static void main(String[] args) throws IOException  {
	
		n = Integer.parseInt(br.readLine());

		graph = new int[n][n];
		
		max_h = -1;
		for(int i=0;i<n;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());	
			for(int j=0;j<n;j++){
				graph[i][j] = Integer.parseInt(st.nextToken());
				max_h = Math.max(max_h, graph[i][j]);
			}
		}
		
		int maxCnt = 1;
		for(int i=1;i<max_h;i++) {
			int cnt = 0;
			visited = new boolean[n][n];
			for(int y=0;y<n;y++) {
				for(int x=0;x<n;x++) {
					if(graph[y][x]>i && !visited[y][x]) {
						dfs(y,x,i);
						cnt++;
					}
				}
			}
			maxCnt = Math.max(maxCnt, cnt);
		}
		
		bw.write(sb.append(maxCnt).toString());
		bw.close();
		br.close();
	}
	
	private static void dfs(int y, int x, int h) {
		visited[y][x] = true;
		
		for(int i=0;i<4;i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(ny<0||ny>=n||nx<0||nx>=n) continue;
			
			if(graph[ny][nx]>h && !visited[ny][nx]) {
				dfs(ny,nx,h);
			}
		}
	}
}