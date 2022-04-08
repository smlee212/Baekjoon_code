import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Main {
    static int n, m; 
    static int maxH = 0;
    static char[][] map;
    static boolean[][] visited;
    static int[] dy = {0,1,0,-1};
    static int[] dx = {1,0,-1,0};
    
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuffer sb = new StringBuffer();		
		StringTokenizer st = new StringTokenizer(br.readLine());		
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		map = new char[n][m];
		
		for(int i=0;i<n;i++) {
			map[i] = br.readLine().toCharArray();
		}
		
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(map[i][j]=='L') {
					visited = new boolean[n][m];
					bfs(i,j,0);
				}
			}
		}		
		
		bw.write(maxH+"\n");
		br.close();
		bw.flush();
		bw.close();
	}	
	
	public static void bfs(int y, int x, int cnt) {
		Queue<Point> q = new LinkedList<>();
		q.add(new Point(y,x,cnt));
		visited[y][x] = true;
		
		while(!q.isEmpty()) {
			y = q.peek().y;
			x = q.peek().x;
			cnt = q.peek().cnt;
			q.poll();
			
			for(int i=0;i<4;i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				
				if(ny<0||ny>=n||nx<0||nx>=m) continue;
				
				if(!visited[ny][nx] && map[ny][nx]=='L') {
					visited[ny][nx] = true;
					q.add(new Point(ny,nx,cnt+1));
				}
			}
		}
		maxH = Math.max(maxH, cnt);
	}	
}

class Point{
	int y;
	int x;
	int cnt;
	Point(int y, int x, int cnt){
		this.y = y;
		this.x = x;		
		this.cnt = cnt;
	}
}