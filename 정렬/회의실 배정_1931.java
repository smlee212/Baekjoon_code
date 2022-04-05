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
  
    static int n;
    static int[][] map;
    
	public static void main(String[] args) throws IOException  {
		n = Integer.parseInt(br.readLine());
		map = new int[n][2];
		
		StringTokenizer st;
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			map[i][0] = Integer.parseInt(st.nextToken());
			map[i][1] = Integer.parseInt(st.nextToken());			
		}

		Arrays.sort(map, new Comparator<int[]>() {

			@Override
			public int compare(int[] o1, int[] o2) {
				if(o1[1]==o2[1]) {
					return o1[0] - o2[0];
				}
				return o1[1]-o2[1];
			}
			
		});
	
		int cnt = 0, endTime = 0;
		
		for(int i=0;i<n;i++) {
			if(endTime <= map[i][0]) {
				endTime = map[i][1];
				cnt++;
			}
		}
		
		bw.write(sb.append(cnt).toString());
		bw.close();
		br.close();
	}	
}