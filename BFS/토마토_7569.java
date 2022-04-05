import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException; 


class Main {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringBuilder sb = new StringBuilder();
  
    static int n,m,h;
    static int[][][] map;
	static Queue<Point> q = new LinkedList<>();
    
    static int[] dz = {0,0,0,0,1,-1};
    static int[] dy = {0,1,0,-1,0,0};
    static int[] dx = {1,0,-1,0,0,0};
    
    public static int check() {
    	int val = -1;
    	for(int i=0;i<h;i++) {
    		for(int j=0;j<n;j++) {
    			for(int k=0;k<m;k++) {
    				if(map[i][j][k] == 0)
    					return -1;
    				val = Math.max(val, map[i][j][k]);
    			}
    		}
    	}
    	return (val==1)?0:val-1;
    }
    
    public static void bfs() {    	
    	while(!q.isEmpty()) {
    		Point p = q.poll();
    		int z = p.z;
    		int y = p.y;
    		int x = p.x;
    		
    		for(int i=0,nz,ny,nx;i<6;i++) {
    			nz = z + dz[i];
    			ny = y + dy[i];
    			nx = x + dx[i];
    			
    			if(nz<0||nz>=h||ny<0||ny>=n||nx<0||nx>=m) continue;

    			if(map[nz][ny][nx] == 0) {
    				q.add(new Point(nz,ny,nx));
    				map[nz][ny][nx] = map[z][y][x] + 1;
    			}
    		} 
    	}
    }
    
	public static void main(String[] args) throws IOException  {
		StringTokenizer st = new StringTokenizer(br.readLine());
		m = Integer.parseInt(st.nextToken());
		n = Integer.parseInt(st.nextToken());
		h = Integer.parseInt(st.nextToken());
		
		map = new int[h][n][m];
		
		for(int i=0;i<h;i++) {
			for(int j=0;j<n;j++) {
				st = new StringTokenizer(br.readLine());
				for(int k=0;k<m;k++) {
					map[i][j][k] = Integer.parseInt(st.nextToken());
					if(map[i][j][k] == 1) q.add(new Point(i,j,k));
				}
			}
		}
		
		bfs();
		
		bw.write(sb.append(check()).toString());
		bw.close();
		br.close();
	}	
}

class Point{
	int z;
	int y;
	int x;
	Point(int z, int y, int x){
		this.z=z;
		this.y=y;
		this.x=x;
	}
}