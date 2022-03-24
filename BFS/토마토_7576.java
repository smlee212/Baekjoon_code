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
  
    static int n, m;
    static int[] dx = {1,-1,0,0};
    static int[] dy = {0,0,-1,1};
    static int[][] graph;
    static Queue<Point> q = new LinkedList<Point>();
    
	public static void main(String[] args) throws IOException  {
	
		StringTokenizer st = new StringTokenizer(br.readLine());		
		m = Integer.parseInt(st.nextToken());
		n = Integer.parseInt(st.nextToken());

		graph = new int[n][m];
		
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<m;j++) {
				graph[i][j] = Integer.parseInt(st.nextToken());	
				if(graph[i][j]==1) q.add(new Point(i,j));
			}
		}		
		
		bfs();
		
		int res = -1;
		boolean check = true;
		Loop1 :
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(graph[i][j]==0) {
					check = false;
					break Loop1;
				}
				res = Math.max(res, graph[i][j]);
			}
		}
		res = (check) ? res-1 : -1;
		bw.write(sb.append(res).toString());
		bw.close();
		br.close();
	}
	
	private static void bfs() {
		while(!q.isEmpty()) {
			int y = q.peek().x;
			int x = q.peek().y;
			q.poll();
			
			for(int i=0;i<4;i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				
				if(ny<0||ny>=n||nx<0||nx>=m) {
					continue;
				}
				
				if(graph[ny][nx]==0) {
					graph[ny][nx] = graph[y][x] + 1;
					q.add(new Point(ny,nx));
				}
			}			
		}
	}
}