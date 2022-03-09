import java.util.*;

class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		while(t-- > 0) {
			int n = sc.nextInt();
			int cnt = 0;
			Queue<Integer> leftQ = new LinkedList<>(); 
			Queue<Integer> rightQ = new LinkedList<>(); 
			for(int i=0;i<n;i++) {
				int val = sc.nextInt();
				leftQ.add(val);
			}
			for(int i=0;i<n;i++) {
				int val = sc.nextInt();
				rightQ.add(val);
			}			
			while(leftQ.size()>0 && rightQ.size()>0) {
				int val = leftQ.poll() + 1000;
				while(rightQ.size() > 0 && val > rightQ.peek()) rightQ.remove();
				if(rightQ.size() > 0 && val == rightQ.peek()) {
					cnt++;
					rightQ.remove();
				}
			}
			System.out.println(cnt/2);
		}		
	}
}