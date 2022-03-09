import java.util.*;

class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String document = sc.nextLine();
		String str = sc.nextLine();
		sc.close();
		
		int cnt = 0;
		for(int i=0;i<document.length()-str.length()+1;i++) {
			if(document.charAt(i)!=str.charAt(0)) continue;
			if(document.substring(i,i+str.length()).equals(str)) {
				cnt++;
				i += str.length()-1;
			}
		}
		
		System.out.print(cnt);
	}
}