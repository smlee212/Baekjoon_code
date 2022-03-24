import java.util.*;
import java.awt.Point;
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
    static char[][] map;
    static int maxCnt = 0;
    
	public static void main(String[] args) throws IOException  {
		n = Integer.parseInt(br.readLine());
		map = new char[n][n];
		for(int i=0;i<n;i++) {
			map[i] = br.readLine().toCharArray();
		}
		
		for(int i=0;i<n;i++) {
			for(int j=0;j<n-1;j++) {
				swap(i,j,i,j+1);
				check();
				swap(i,j,i,j+1);
			}
		}
		
		for(int j=0;j<n;j++) {
			for(int i=0;i<n-1;i++) {
				swap(i,j,i+1,j);
				check();
				swap(i,j,i+1,j);
			}
		}		
		
		bw.write(sb.append(maxCnt).toString());
		bw.close();
		br.close();
	}
	
	public static void swap(int a, int b, int c, int d) {
		char temp = map[a][b];
		map[a][b] = map[c][d];
		map[c][d] = temp;
	}
	
	public static void check() {
		// 가로
		for(int i=0;i<n;i++) {
			int cnt = 1;
			for(int j=0;j<n-1;j++) {
				if(map[i][j] == map[i][j+1]) {
					cnt++;
				}
				else {
					cnt = 1;
				}
				
				maxCnt = Math.max(maxCnt, cnt);
			}
		}
		
		// 세로
		for(int i=0;i<n;i++) {
			int cnt = 1;
			for(int j=0;j<n-1;j++) {
				if(map[j][i] == map[j+1][i]) {
					cnt++;
				}
				else {
					cnt = 1;
				}
				
				maxCnt = Math.max(maxCnt, cnt);
			}
		}
	}
}