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
	static StringTokenizer st;	
  
    static int t, n, x1, y1, x2, y2;
    static int[][] graph;
    static int[] dx = {1,1,2,2,-1,-1,-2,-2};
    static int[] dy = {2,-2,1,-1,2,-2,1,-1};
    static boolean[][] visited;
    
	public static void main(String[] args) throws IOException  {
		t = Integer.parseInt(br.readLine());
		
		while(t-->0) {		
			n = Integer.parseInt(br.readLine());
	
			graph = new int[n][n];
			visited = new boolean[n][n];
			
			st = new StringTokenizer(br.readLine());
			x1 = Integer.parseInt(st.nextToken());
			y1 = Integer.parseInt(st.nextToken());

			st = new StringTokenizer(br.readLine());
			x2 = Integer.parseInt(st.nextToken());
			y2 = Integer.parseInt(st.nextToken());

			bfs();
			
			sb.append(graph[y2][x2] + "\n");
		}
		
		bw.write(sb.toString());
		bw.close();
		br.close();
	}
	
	private static void bfs() {
	    Queue<Pair> q = new LinkedList<>();
	    q.add(new Pair(y1,x1));
		visited[y1][x1] = true;
		
		while(!q.isEmpty()) {
			Pair p = q.poll();
			int y = p.getY();
			int x = p.getX();
			
			if(y==y2 && x==x2) {
				break;
			}
			
			for(int i=0;i<8;i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				
				if(ny>=0 && ny<n && nx>=0 && nx<n && !visited[ny][nx]) {
					q.add(new Pair(ny,nx));
					visited[ny][nx] = true;
					graph[ny][nx] = graph[y][x] + 1;
				}
			}
			
		}
	}
}

class Pair{
	private int y;
	private int x;
	
	Pair(int y, int x){
		this.y = y;
		this.x = x;
	}
	
	public int getY() {
		return y;
	}
	
	public int getX() {
		return x;
	}
}