import java.util.*;

class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Queue<Integer> q = new LinkedList<>(); 
		int n = sc.nextInt();
		
		for(int i=1;i<=n;i++) q.add(i);
		
		while(q.size() > 1) {
			q.remove();
			int val = q.poll();
			q.offer(val);			
		}
		
		System.out.print(q.poll());
	}
}