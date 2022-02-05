import java.util.Scanner;

class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int m = sc.nextInt();
		int n = sc.nextInt();
		sc.close();
		
		int arr[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
		String str[] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
		
		int sum = n;
		for(int i=0;i<m;i++) sum += arr[i];		
		
		System.out.println(str[sum%7]);		
	}
}
