import java.util.*;

class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Queue<Integer> q = new LinkedList<>(); 
		
		int n = sc.nextInt(), k = sc.nextInt();
		String res = "<";
		
		for(int i=1;i<=n;i++) q.add(i);
		
		while(q.size() > 1) {
			for(int i=0;i<k-1;i++) {
				int val = q.poll();
				q.offer(val);
			}
			res += q.poll() + ", ";
		}
		res += q.poll() + ">";
		
		System.out.println(res);
	}
}