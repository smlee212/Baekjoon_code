import java.util.HashMap;
import java.util.Map.Entry;
import java.util.Set;
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
  
    static int n,m;
    static String[] arr;
    static HashMap<String, Integer> map = new HashMap<>();
    
	public static void main(String[] args) throws IOException  {
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		arr = new String[n+1];
		
		for(int i=1;i<=n;i++) {
			String str = br.readLine();
			map.put(str, i);
			arr[i] = str;
		}
		
		for(int i=0;i<m;i++) {
			String str = br.readLine();
			if('0'>str.charAt(0) || str.charAt(0)>'9') {
				sb.append(map.get(str) + "\n");
			}
			else {
				sb.append(arr[Integer.parseInt(str)] + "\n");
			}
		}
		
		bw.write(sb.toString());
		bw.close();
		br.close();
	}	
}