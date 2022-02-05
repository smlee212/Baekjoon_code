import java.util.Scanner;

class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		
		for(int i=n;i>=0;i--) {
			String s = "";
			for(int j=0;j<i;j++) s += "*";
			System.out.println(s);
		}	
		sc.close();
	}
}
