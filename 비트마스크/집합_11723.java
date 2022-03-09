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
    
	public static void main(String[] args) throws IOException  {
		int t = Integer.parseInt(br.readLine());
		int bitmask = 0;
		
		while(t-->0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String op = st.nextToken();
			int num;
			switch(op) {
			case "add":
				num = Integer.parseInt(st.nextToken());
				bitmask |= (1<<(num-1));
				break;
			case "remove":
				num = Integer.parseInt(st.nextToken());
				bitmask &= ~(1<<(num-1));
				break;
			case "check":
				num = Integer.parseInt(st.nextToken());
				sb.append((bitmask & (1<<(num-1))) != 0 ? "1\n" : "0\n");
				break;
			case "toggle":
				num = Integer.parseInt(st.nextToken());
				bitmask ^= (1<<(num-1));
				break;
			case "all":
				bitmask |= (~0);
				break;
			case "empty":
				bitmask &= 0;
				break;
			}
		}
        bw.write(sb.toString());
        bw.close();
        br.close();
	}
}