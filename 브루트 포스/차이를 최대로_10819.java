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
  
    static int n, res;
    static int[] map;
    static boolean[] visited;
    
	public static void main(String[] args) throws IOException  {
		n = Integer.parseInt(br.readLine());
		res = 0;
		map = new int[n];
		visited = new boolean[n];
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++) {
			map[i] = Integer.parseInt(st.nextToken());
		}
		
		dfs(0,0,0);
		
		bw.write(sb.append(res).toString());
		bw.close();
		br.close();
	}
	
	public static void dfs(int cnt, int sum, int temp) {
		if(cnt==n) {
			res = Math.max(res, sum);
		}

		for(int i=0;i<n;i++) {
			if(visited[i]) continue;
			
			visited[i] = true;
			dfs(cnt+1, cnt==0?0:sum+Math.abs(temp-map[i]), map[i]);
			visited[i] = false;
		}
	}
}