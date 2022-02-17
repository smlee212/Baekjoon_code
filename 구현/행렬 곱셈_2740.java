import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(), m = sc.nextInt();
		int[][] A = new int[n][m];
		
		for(int i=0;i<n;i++) 
			for(int j=0;j<m;j++) 
				A[i][j] = sc.nextInt();
			
		sc.nextInt(); 
		int k = sc.nextInt();
		int[][] B = new int[m][k];

		for(int i=0;i<m;i++) 
			for(int j=0;j<k;j++) 
				B[i][j] = sc.nextInt();

		for(int i=0;i<n;i++) {
			for(int j=0;j<k;j++) {
				int num = 0;
				for(int t=0;t<m;t++) {
					num += A[i][t] * B[t][j];
				}
				System.out.printf("%d ",num);
			}
			System.out.println();
		}		
	}
}