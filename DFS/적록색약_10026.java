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
  
    static int n;
    static char[][] graph;
    static int[] dx = {1,0,-1,0};
    static int[] dy = {0,1,0,-1};
    static boolean[][] visited;
    static boolean[][] visited_weakness;
    
	public static void main(String[] args) throws IOException  {
	
		n = Integer.parseInt(br.readLine());

		graph = new char[n][n];
		visited = new boolean[n][n];
		visited_weakness = new boolean[n][n];
		
		for(int i=0;i<n;i++) {
			String str = br.readLine();
			for(int j=0;j<n;j++) {
				graph[i][j] = str.charAt(j);
			}
		}
		
		int cnt = 0, cnt_weakness = 0;
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if(!visited[i][j]) {
					dfs(i,j);
					cnt++; 
				}
				if(!visited_weakness[i][j]) {
					dfs_weakness(i,j);
					cnt_weakness++;
				}
			}
		}
		
		bw.write(sb.append(cnt+" "+cnt_weakness).toString());
		bw.close();
		br.close();
	}
	
	private static void dfs(int y, int x) {
		char c = graph[y][x];
		visited[y][x] = true;
		
		for(int i=0;i<4;i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(ny<0||ny>=n||nx<0||nx>=n) continue;
			
			if(graph[ny][nx]==c && !visited[ny][nx]) {
				dfs(ny,nx);
			}
		}
	}
	
	private static void dfs_weakness(int y, int x) {
		visited_weakness[y][x] = true;
		char c = graph[y][x];
		
		for(int i=0;i<4;i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(ny<0||ny>=n||nx<0||nx>=n) continue;	

			if(c=='B') {
				if(graph[ny][nx]==c && !visited_weakness[ny][nx]) {
					dfs_weakness(ny,nx);
				}
			}
			else {
				if((graph[ny][nx]=='R' || graph[ny][nx]=='G') && !visited_weakness[ny][nx]) {
					dfs_weakness(ny,nx);
				}
			}
		}
	}
}