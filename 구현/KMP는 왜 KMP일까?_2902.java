import java.util.Scanner;

class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str = sc.nextLine();
		sc.close();
		
		String res = "";
		for(int i = 0; i < str.length() ; i++) {
			if(str.charAt(i)>='A'&& str.charAt(i)<='Z')
				res += str.charAt(i);
		}
		System.out.println(res);
	}
}