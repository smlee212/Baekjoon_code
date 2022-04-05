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
    
    public static void div(int y, int x, int size) {
    	if(check(y,x,size)) {
    		sb.append(map[y][x]);
    		return;
    	}
    	
    	int nextSize = size / 2;
    	sb.append("(");
    	div(y,x,nextSize);
    	div(y,x+nextSize,nextSize);
    	div(y+nextSize,x,nextSize);
    	div(y+nextSize,x+nextSize,nextSize);
    	sb.append(")");
    }
    
    public static boolean check(int y, int x, int size) {
    	int temp = map[y][x];
    	
    	for(int i=y;i<y+size;i++) {
    		for(int j=x;j<x+size;j++) {
    			if(map[i][j] != temp) {
    				return false;
    			}
    		}
    	}
    	
    	return true;
    }
    
	public static void main(String[] args) throws IOException  {
		n = Integer.parseInt(br.readLine());
		map = new int[n][n];
		
		for(int i=0;i<n;i++) {
			String str = br.readLine();
			for(int j=0;j<n;j++) {
				map[i][j] = str.charAt(j) - '0';
			}
		}
		
		div(0,0,n);
		
		bw.write(sb.toString());
		bw.close();
		br.close();
	}	
}