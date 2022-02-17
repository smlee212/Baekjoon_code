import java.util.*;

class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] score1 = new int[n];
		int[] score2 = new int[n];
		int[] score3 = new int[n];
		
		for(int i=0;i<n;i++) {
			score1[i] = sc.nextInt();
			score2[i] = sc.nextInt();
			score3[i] = sc.nextInt();
		}
		
		for(int i=0;i<n-1;i++) {
			int a = score1[i], b = score2[i], c = score3[i];
			for(int j=i+1;j<n;j++) {
				if(a == score1[j]) {
					score1[i] = 0;
					score1[j] = 0;
				}
				if(b == score2[j]) {
					score2[i] = 0;
					score2[j] = 0;
				}
				if(c == score3[j]) {
					score3[i] = 0;
					score3[j] = 0;
				}
			}
		}
		
		for(int i=0;i<n;i++) 
			System.out.println(score1[i] + score2[i] + score3[i]);
		
	}
}