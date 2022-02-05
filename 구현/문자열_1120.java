import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s1 = sc.next();
		String s2 = sc.next();
		int res = s1.length();
		sc.close();
		for(int i=0;i<s2.length() - s1.length() + 1; i++) {
			int temp = 0;			
			for(int j=0;j<s1.length();j++) {
				if(s1.charAt(j)!=s2.charAt(j+i))
					temp++;
			}			
			res = (res<temp)?res:temp;
		}
		System.out.println(res);
	}	
}
