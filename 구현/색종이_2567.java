import java.util.*;

class Main {
	private static int[][] map = new int[101][101];
	private static int[] dx = {-1,1,0,0};
	private static int[] dy = {0,0,-1,1};
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for(int i=0;i<n;i++) {
			int x = sc.nextInt();
			int y = sc.nextInt();
			for(int j=x;j<x+10;j++) {
				for(int k=y;k<y+10;k++) {
					map[j][k] = 1;
				}
			}
		}
		
		int res = 0;
		for(int i=0;i<map.length;i++) {
			for(int j=0;j<map[i].length;j++) {
				if(map[i][j] == 1) {
					for(int k=0;k<4;k++) {
						int nx = i+dx[k];
						int ny = j+dy[k];
						
						if(map[nx][ny]==0||nx<0||nx>100||ny<0||ny>100) {
							res++;
						}
					}
				}
			}		
		}
		System.out.print(res);
	}
}