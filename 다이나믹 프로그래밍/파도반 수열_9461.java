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
    static long[] map;
    
    public static long func() {
    	if(n<3) {
    		return 1;
    	}
    	
    	map[1] = 1;
    	map[2] = 1;
    	
    	for(int i=3;i<=n;i++) {
    		map[i] = map[i-3] + map[i-2];
    	}
    	
    	return map[n];
    }
    
	public static void main(String[] args) throws IOException  {
		t = Integer.parseInt(br.readLine());
		
		while(t-->0) {
			n = Integer.parseInt(br.readLine());
			map = new long[n+1];
			map[0] = 0;

			sb.append(func()+"\n");
		}
		
		bw.write(sb.toString());
		bw.close();
		br.close();
	}	
}