import java.util.*;

class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str = sc.nextLine();
		String[] arr = new String[str.length()];
		int len = str.length();
		
		for(int i=0;i<len;i++) {
			arr[i] = str.substring(i,len);
		}
		
		Arrays.sort(arr);
		
		for(int i=0;i<len;i++) {
			System.out.println(arr[i]);			
		}
	}
}