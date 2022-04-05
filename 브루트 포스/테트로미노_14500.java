import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

class Main {
    static int n, m, maxSum; 
    static int[] dy = {0,1,0,-1};
    static int[] dx = {1,0,-1,0};
    static int[][] ddx = {{0, 0, 0, 1}, {0, 1, 2, 1}, {0, 0, 0, -1}, {0, -1, 0, 1}};
    static int[][] ddy = {{0, 1, 2, 1}, {0, 0, 0, 1}, {0, 1, 2, 1}, {0, 1, 1, 1}};
    static int[][] map;
    static boolean[][] visited;
    
    
    
    public static void dfs(int y, int x, int cnt, int sum) {
    	if(cnt>=4) {
    		maxSum = Math.max(sum, maxSum);
    		return;
    	}
    	
    	for(int i=0;i<4;i++) {
    		int ny = y + dy[i];
    		int nx = x + dx[i];
    		
    		if(ny<0||ny>=n||nx<0||nx>=m) continue;
    		
    		if(!visited[ny][nx]) {
    			visited[ny][nx] = true;
    			dfs(ny,nx,cnt+1,sum+map[ny][nx]);
    			visited[ny][nx] = false;
    		}
    		
    	}
    }
    
    public static void ex_shape(int y, int x) {
    	for(int i=0;i<4;i++) {
    		boolean isOut = false;
    		int sum = 0;
    		
    		for(int j=0;j<4;j++) {
    			int ny = y + ddy[i][j];
    			int nx = x + ddx[i][j];
    			
    			if(ny<0||ny>=n||nx<0||nx>=m) {
    				isOut = true;
    				break;
    			}
    			
    			sum += map[ny][nx];
    		}
    		if(!isOut) {
    			maxSum = Math.max(maxSum, sum);
    		}
    	}
    }
    
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuffer sb = new StringBuffer();
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		maxSum = 0;
		
		map = new int[n][m];
		visited = new boolean[n][m];
		
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<m;j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				visited[i][j] = true;
				dfs(i,j,1,map[i][j]);
				visited[i][j] = false;
				
				ex_shape(i,j);
			}
		}
		
		
		
		bw.write(sb.append(maxSum).toString());
		br.close();
		bw.flush();
		bw.close();
	}	
}