import java.util.*;

class Main {
	static char[][] map;
	public static void func(int n, int x, int y) {
		if(n==1) {
			map[x][y] = '*';
			return;
		}
		
		int len = 4 * (n-1) + 1;
		
		for(int j=y;j<y+len;j++) {
			map[x][j] = '*';
			map[x+len-1][j] = '*';
		}
		
		for(int i=x;i<x+len;i++) {
			map[i][y] = '*';
			map[i][y+len-1] = '*';
		}
		
		func(n-1,x+2,y+2);	
		return;		
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(); sc.close();
		int N = 4 * (n-1) + 1;
		map = new char[N][N];
		
		for(int i=0;i<N;i++) for(int j=0;j<N;j++) map[i][j] = ' ';
		
		func(n,0,0);
		
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				System.out.print(map[i][j]);
			}
			System.out.println();
		}
	}
}