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
  
    static long n, m;
    static Queue<node> q;
    
	public static void main(String[] args) throws IOException  {
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Long.parseLong(st.nextToken());
		m = Long.parseLong(st.nextToken());
		q = new LinkedList<node>();	  
		
		sb.append(bfs());
		
		bw.write(sb.toString());
		bw.close();
		br.close();
	}
	
	public static int bfs() {
	    q.add(new node(n,1));
		
		while(!q.isEmpty()) {
			node nd = q.poll();
			long x = nd.x;
			int cnt = nd.cnt;
			
			long nx = x<<1;
			if(nx<m) {
				q.add(new node(nx,cnt+1));
			}
			else if(nx==m) {
				return cnt+1;
			}
			
			nx = (x<<1) + (x<<3) + 1;
			if(nx<m) {
				q.add(new node(nx,cnt+1));
			}
			else if(nx==m) {
				return cnt+1;
			}
		}
		return -1;
	}
}

class node {
	long x;
	int cnt;
	node(long x, int cnt){
		this.x = x;
		this.cnt = cnt;
	}
}