import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

class Main {
    static int k, n; 
    static int[] arr;
    
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuffer sb = new StringBuffer();
		StringTokenizer st;
		long start = 0, end = 0, mid;
		long cnt;
		
		st = new StringTokenizer(br.readLine());
		k = Integer.parseInt(st.nextToken());
		n = Integer.parseInt(st.nextToken());
		arr = new int[k];
		
		for(int i=0;i<k;i++) {
			arr[i] = Integer.parseInt(br.readLine());
			end = Math.max(arr[i], end);
		}		
		
		end++;
		
		while(start<end) {
			cnt = 0;
			mid = (start + end) / 2;
			
			for(int i=0;i<k;i++) {
				cnt += arr[i]/mid;
			}
			
			if(cnt < n) {
				end = mid;
			}
			else {
				start = mid + 1;
			}
		}
		
		bw.write(sb.append(start-1).toString());
		br.close();
		bw.flush();
		bw.close();
	}	
}