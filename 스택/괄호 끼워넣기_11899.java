import java.util.*;

class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str = sc.next();
		int cnt = 0, buf = 0;
		for(int i=0;i<str.length();i++) {
			if(str.charAt(i)=='(') {
				cnt++;
			}
			else {
				if(cnt==0) {
					buf++;
				}
				else {
					cnt--;
				}
			}
		}
		System.out.print(cnt+buf);

	}
}