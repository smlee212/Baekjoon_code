import java.util.*;

class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(), m = sc.nextInt();
		LinkedList<Integer> dq = new LinkedList<>();
		int cnt = 0;
		
		for(int i=1;i<=n;i++) dq.offer(i);
		
		int[] a = new int[m];		
		for(int i=0;i<m;i++) a[i] = sc.nextInt();	
		
		for(int i=0;i<m;i++) {
			int targetIdx = dq.indexOf(a[i]);
			int midIdx;
			
			if(dq.size()%2==0) {
				midIdx = dq.size()/2 - 1;
			}
			else {
				midIdx = dq.size()/2;
			}
			
			if(targetIdx <= midIdx) {
				for(int j=0;j<targetIdx;j++) {
					int temp = dq.pollFirst();
					dq.offerLast(temp);
					cnt++;
				}
			}
			else {
				for(int j=0;j<dq.size()-targetIdx;j++) {
					int temp = dq.pollLast();
					dq.offerFirst(temp);
					cnt++;
				}
			}
			
			dq.pollFirst();
		}
		
		System.out.println(cnt);		
	}
}