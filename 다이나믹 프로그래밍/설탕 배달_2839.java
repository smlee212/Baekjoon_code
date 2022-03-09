import java.util.*;

class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int min = n;
		sc.close();
		int[] dp = new int[n/5+1]; // index는 5kg 봉지 개수
		for(int i=0;i<dp.length;i++) {
			int diff = n - 5*i;
			dp[i] = (diff%3==0) ? diff/3 + i : n; 
			if(dp[i]<min) min = dp[i];
		}
		if(min==n) min = -1;
		System.out.print(min);
	}
}