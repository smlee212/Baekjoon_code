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
  
    static int n, cnt=0;
 
    
	public static void main(String[] args) throws IOException  {
		n = Integer.parseInt(br.readLine());
		
		while(n>=5) {
			cnt += n / 5;
			n /= 5;
		}
		
		bw.write(sb.append(cnt).toString());
		bw.close();
		br.close();
	}	
}
