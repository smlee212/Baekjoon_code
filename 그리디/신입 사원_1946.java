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
  
    static int T,n;
    static int[] arr;
    
	public static void main(String[] args) throws IOException  {
		StringTokenizer st;
		T = Integer.parseInt(br.readLine());
		
		while(T-->0) {
			n = Integer.parseInt(br.readLine());
			arr = new int[n+1];
			
			for(int i=0;i<n;i++) {
				st = new StringTokenizer(br.readLine());
				int s = Integer.parseInt(st.nextToken());
				arr[s] = Integer.parseInt(st.nextToken());
			}
			
			int res = 1;
			int min = arr[1];
			for(int i=2;i<=n;i++) {
				if(arr[i] < min) {
					res++;
					min = arr[i];
				}
			}
			
			sb.append(res+"\n");
		}
		
		bw.write(sb.toString());
		bw.close();
		br.close();
	}
}