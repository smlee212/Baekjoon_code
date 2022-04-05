import java.util.ArrayList;
import java.util.Collections;
import java.util.Deque;
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
  
    static int t,n;
    static char[] p;
    static Deque<Integer> dq;
    
    public static void func() {
    	boolean isFront = true;
		for(char c : p) {
			if(c == 'R') {
				isFront = !isFront;
				continue;
			}

			if(isFront) {
				if(dq.pollFirst()==null) {
					sb.append("error\n");
					return;
				}
				
			}
			else {
				if(dq.pollLast()==null) {
					sb.append("error\n");
					return;
				}
			}
		}
		
		sb.append('[');
		
		if(isFront && dq.size()>0) {
			sb.append(dq.pollFirst());
			while(!dq.isEmpty())
				sb.append(","+dq.pollFirst());
		}
		else if(!isFront && dq.size()>0){
			sb.append(dq.pollLast());
			while(!dq.isEmpty())
				sb.append(","+dq.pollLast());
		}
		
		sb.append("]\n");
    }
    
	public static void main(String[] args) throws IOException  {
		t = Integer.parseInt(br.readLine());

		while(t-->0) {
			p = br.readLine().toCharArray();
			n = Integer.parseInt(br.readLine());
			dq = new LinkedList<>();
			
			StringTokenizer st = new StringTokenizer(br.readLine(),",[]");
			for(int i=0;i<n;i++) {
				dq.add(Integer.parseInt(st.nextToken()));
			}
			
			
			func();
		}		
		
		
		bw.write(sb.toString());
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