import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

class Main {
    static int n, m, t; 
    static int[][] prevMap;
    static int[][] nextMap;
    static int airCleaner;
    static int[] dy = {1,0,-1,0};
    static int[] dx = {0,-1,0,1};
    
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuffer sb = new StringBuffer();		
		StringTokenizer st = new StringTokenizer(br.readLine());		
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		t = Integer.parseInt(st.nextToken());

		prevMap = new int[n][m];
		nextMap = new int[n][m];

		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0, val;j<m;j++) {
				val = Integer.parseInt(st.nextToken());
				prevMap[i][j] = nextMap[i][j] = val;
				if(val==-1) airCleaner = i;
			}
		}
		
		while(t-->0) {
			for(int i=0;i<n;i++) {
				for(int j=0;j<m;j++) {
					if(prevMap[i][j]<5) continue;
					diffusion(i,j);
				}
			}		
			action();				
			ArrayCopy();	
		}		

		sb.append(sumDust());
		
		bw.write(sb.toString());
		br.close();
		bw.flush();
		bw.close();
	}	
	
	public static void ArrayCopy() {
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				prevMap[i][j] = nextMap[i][j];
			}
		}
	}
	
	public static void diffusion(int y, int x) {
		int cnt = 0;
		int divVal = prevMap[y][x] / 5;		
		
		for(int i=0;i<4;i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(ny<0||ny>=n||nx<0||nx>=m) continue;
		
			if(prevMap[ny][nx]>=0) {
				nextMap[ny][nx] += divVal;
				cnt++;
			}
		}
		
		nextMap[y][x] -= divVal * cnt;
	}	
	
	public static void action() {
		int y1 = airCleaner - 1;
		
		for(int i=y1-1, j=0;i>0;i--) {
			nextMap[i][j] = nextMap[i-1][j]; 
		}
		for(int i=0, j=0;j<m-1;j++) {
			nextMap[i][j] = nextMap[i][j+1]; 
		}
		for(int i=0, j=m-1;i<y1;i++) {
			nextMap[i][j] = nextMap[i+1][j]; 
		}
		for(int i=y1, j=m-1;j>1;j--) {
			nextMap[i][j] = nextMap[i][j-1];
		}
		nextMap[y1][1] = 0;

		int y2 = airCleaner;
		
		for(int i=y2+1, j=0;i<n-1;i++) {
			nextMap[i][j] = nextMap[i+1][j]; 
		}
		for(int i=n-1, j=0;j<m-1;j++) {
			nextMap[i][j] = nextMap[i][j+1]; 
		}
		for(int i=n-1, j=m-1;i>y2;i--) {
			nextMap[i][j] = nextMap[i-1][j]; 
		}
		for(int i=y2, j=m-1;j>1;j--) {
			nextMap[i][j] = nextMap[i][j-1];
		}
		nextMap[y2][1] = 0;
	}
	
	public static int sumDust() {
		int sum = 0;
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(nextMap[i][j]>0) sum += nextMap[i][j];
			}
		}
		return sum;
	}
}