import java.util.*;

class Main {
	static int[][] bingo;
	static int cnt;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		bingo = new int[5][5];
		cnt = 0;
		
		for(int i=0;i<5;i++) for(int j=0;j<5;j++) bingo[i][j] = sc.nextInt();

		for(int t=1;t<=25;t++) {
			int num = sc.nextInt();
			
			for(int i=0;i<5;i++) for(int j=0;j<5;j++) if(bingo[i][j] == num) bingo[i][j] = 0;
			
			row();
			col();
			lDiagonal();
			rDiagonal();
			
			if(cnt >= 3) {
				System.out.println(t);
				break;
			}
			cnt = 0;			
		}
	}
	public static void row() {
		for(int i=0;i<5;i++) {
			int zeroCnt = 0;
			for(int j=0;j<5;j++) {
				if(bingo[i][j]!=0) break; 
				zeroCnt++;
			}
			if(zeroCnt==5) cnt++;
		}
	}

	public static void col() {
		for(int j=0;j<5;j++) {
			int zeroCnt = 0;
			for(int i=0;i<5;i++) {
				if(bingo[i][j]!=0) break; 
				zeroCnt++;
			}
			if(zeroCnt==5) cnt++;
		}		
	}
		
	public static void lDiagonal() {
		int zeroCnt = 0;
		for(int i=0;i<5;i++) {
			if(bingo[i][i]!=0) break;
			zeroCnt++;
		}
		if(zeroCnt==5) cnt++;
	}
	
	public static void rDiagonal() {
		int zeroCnt = 0;
		for(int i=0;i<5;i++) {
			if(bingo[i][4-i]!=0) break;
			zeroCnt++;
		}
		if(zeroCnt==5) cnt++;		
	}	
}