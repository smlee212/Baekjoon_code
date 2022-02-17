import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for(int i=0;i<t;i++) {
			int n = sc.nextInt();	
			String[] school = new String[n];
			int index = 0;
			int buf = 0;
			for(int j=0;j<n;j++) {
				school[j] = sc.next();
				int temp = sc.nextInt();
				if(temp>buf) {
					buf=temp;
					index=j;
				}
			}		
			System.out.println(school[index]);
		}
		sc.close();
	}
}