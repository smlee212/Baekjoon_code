import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		sc.close();
		
		int t = 1, i = 1;
		int sum_a = 0, sum_b = 0;
		
		while(t<=b) {
			for(int j=0;j<i;j++) {
				sum_a += (t<a)?i:0;
				sum_b += (t<=b)?i:0;
				t++;
			}
			i++;
		}		
		
		System.out.println(sum_b - sum_a);
	}	
}