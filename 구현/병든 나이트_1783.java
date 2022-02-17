import java.util.*;

class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(), m = sc.nextInt();
		int total_cnt = 0;
		if(n==1);
		else if(n==2) {
			total_cnt = (m-1)/2;
			total_cnt = total_cnt >= 4 ? 3 : total_cnt;
		}
		else if(m<7) {
			total_cnt = m-1;
			total_cnt = total_cnt >= 4 ? 3 : total_cnt;
		}
		else {
			total_cnt = 4 + m - 7;
		}
		
		System.out.println(total_cnt+1);
	}	
}