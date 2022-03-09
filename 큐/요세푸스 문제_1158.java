import java.util.*;

class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(), k = sc.nextInt();
		ArrayList<Integer> arr = new ArrayList<>();
		int a = 0;
		String res = "<";
		
		for(int i=1;i<=n;i++) arr.add(i);
		while(arr.size()>1) {
			a = (a+k-1)%(n--);
			res += arr.get(a) + ", ";			
			arr.remove(a);			
		}
		res += arr.get(0) + ">";
		
		System.out.print(res);
		sc.close();
	}
}