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
    static int[] arr;
    
	public static void main(String[] args) throws IOException  {
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		arr = new int[n];
		int l=0, r=0;
		for(int i=0;i<n;i++) {
			arr[i] = Integer.parseInt(br.readLine());
			l = arr[i] > l ? arr[i] : l;
			r += arr[i];
		}
		
		while(l<=r) {
			int mid = (l+r)/2;
			int sum = 0, cnt = 0;
			
			for(int i=0;i<n;i++) {
				if(sum + arr[i] > mid) {
					sum = 0;
					cnt++;
				}
				sum += arr[i];
			}
			
			if(sum != 0) cnt++;
			if(cnt <= m) r = mid - 1;
			else l = mid + 1;
		}
		
		bw.write(sb.append(l).toString());
		bw.close();
		br.close();
	}
}