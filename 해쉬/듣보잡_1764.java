import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		sc.nextLine();
		HashSet<String> has = new HashSet<String>();
		ArrayList<String> res = new ArrayList<String>();
		
		for(int i=0;i<n;i++) {
			String str = sc.nextLine();
			has.add(str);
		}
		for(int i=0;i<m;i++) {
			String str = sc.nextLine();
			if(has.contains(str))
				res.add(str);
		}
		sc.close();
		
		Collections.sort(res);
		
		System.out.println(res.size());		
		for(String i : res)
			System.out.println(i);
	}
}
