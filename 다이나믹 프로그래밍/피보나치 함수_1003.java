import java.util.*;

class Main {
	private static int[] d0, d1;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		d0 = new int[41];
		d1 = new int[41];
		
		d0[0] = 1; d0[1] = 0;
		d1[0] = 0; d1[1] = 1;
		
		while(t-->0) {
			int n = sc.nextInt(); 
			for(int i=2;i<=n;i++) {
				d0[i] = d0[i-2] + d0[i-1];
				d1[i] = d1[i-2] + d1[i-1];
			}
			System.out.println(d0[n]+" "+d1[n]);
		}
		sc.close();
	}
}