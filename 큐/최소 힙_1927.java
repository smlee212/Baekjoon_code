import java.util.*;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException; 

class Main {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringBuilder sb = new StringBuilder();
  
    static int n,m;
    static PriorityQueue<Integer> pq = new PriorityQueue<>();
    
	public static void main(String[] args) throws IOException  {
		n = Integer.parseInt(br.readLine());
		
		for(int i=0;i<n;i++) {
			int x = Integer.parseInt(br.readLine());		
			if(x==0) {
				int y = pq.size()>0 ? pq.poll() : 0;				
				sb.append(y+"\n");				
			}
			else{
				pq.add(x);
			}
		}
		
		bw.write(sb.toString());
		bw.close();
		br.close();
	}
}