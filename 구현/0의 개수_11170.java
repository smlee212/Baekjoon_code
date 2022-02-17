import java.util.*;

class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		
		while(T-->0) {
			int n = sc.nextInt();
			int m = sc.nextInt();
			int count = 0;
			
			for(int i=n;i<=m;i++) {
				int temp = i;
				if(i==0) {
					count++;
					continue;
				}
				
				while(temp>1) {
					if(temp % 10 == 0) count++;					
					temp /= 10;
				}
			}
			
			System.out.println(count);
		}
		sc.close();
	}
}