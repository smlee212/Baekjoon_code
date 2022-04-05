import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
import java.io.IOException; 


class Main {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringBuilder sb = new StringBuilder();
  
    static int n;
    static int[][] map;
    static int[] cnt = {0, 0, 0}; // -1, 0, 1 순서
    
    public static boolean check(int y, int x, int size) {
    	int num = map[y][x];
    	for(int i=y;i<y+size;i++) {
    		for(int j=x;j<x+size;j++) {
    			if(map[i][j] != num)
    				return false;
    		}
    	}
    	cnt[num+1]++;
    	return true;
    }
    
    public static void func(int y, int x, int size) {
    	if(check(y,x,size)) {
    		return;
    	}
    	
    	int nextSize = size / 3;
    	
    	func(y,x,nextSize);
    	func(y,x+nextSize,nextSize);
    	func(y,x+nextSize+nextSize,nextSize);
    	func(y+nextSize,x,nextSize);
    	func(y+nextSize,x+nextSize,nextSize);
    	func(y+nextSize,x+nextSize+nextSize,nextSize);
    	func(y+nextSize+nextSize,x,nextSize);
    	func(y+nextSize+nextSize,x+nextSize,nextSize);
    	func(y+nextSize+nextSize,x+nextSize+nextSize,nextSize);
    }
    
	public static void main(String[] args) throws IOException  {
		n = Integer.parseInt(br.readLine());
		map = new int[n][n];
		
		StringTokenizer st;
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<n;j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		func(0,0,n);
		
		sb.append(cnt[0]+"\n"+cnt[1]+"\n"+cnt[2]);
		
		bw.write(sb.toString());
		bw.close();
		br.close();
	}	
}