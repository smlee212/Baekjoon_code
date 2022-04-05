import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
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
  
    static int n, val, cnt;
    static ArrayList<Integer> count = new ArrayList<>();
    static int[] dy = {1,0,-1,0};
    static int[] dx = {0,1,0,-1};
    static int[][] map;
    static boolean[][] visited;
    
    public static void dfs(int y, int x) {
    	cnt++;
    	map[y][x] = val;
    	visited[y][x] = true;
    	
    	for(int i=0;i<4;i++) {
    		int ny = y + dy[i];
    		int nx = x + dx[i];
    		
    		if(ny<0||ny>=n||nx<0||nx>=n) continue; 
    			
    		if(map[ny][nx]==1 && !visited[ny][nx]) {    			
    			dfs(ny,nx);
    		}
    	}
    }
    
	public static void main(String[] args) throws IOException  {
		n = Integer.parseInt(br.readLine());
		
		map = new int[n][n];
		visited = new boolean[n][n];

		for(int i=0;i<n;i++) {
			char[] str = br.readLine().toCharArray();
			for(int j=0;j<n;j++) {
				map[i][j] = str[j] - '0';
			}
		}
		
		val = 1; cnt = 0;
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if(map[i][j]==1 && !visited[i][j]) {
					dfs(i,j);
					count.add(cnt);
					val++;
					cnt = 0;
				}
			}
		}
		
		Collections.sort(count);
		
		sb.append(count.size()+"\n");
		
		for(int i=0;i<count.size();i++) {
			sb.append(count.get(i)+"\n");
		}
		
		bw.write(sb.toString());
		bw.close();
		br.close();
	}	
}
