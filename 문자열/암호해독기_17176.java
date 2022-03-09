import java.util.*;

class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		
		int[] password = new int[53];	

		for(int i=0;i<53;i++) {
			password[i] = 0;
		}
		
		for(int i=0;i<n;i++) {
			int index = sc.nextInt();
			password[index]++;
		}
		
		sc.nextLine();
		String str = sc.nextLine();
		for(int i=0;i<n;i++) {
			if(Character.isUpperCase(str.charAt(i))) {
				password[str.charAt(i)-'A'+1]--;
			}
			else if(Character.isLowerCase(str.charAt(i))) {
				password[str.charAt(i)-'a'+27]--;
			}
			else {			
				password[0]--;
			}
		}

		boolean check = true;
		for(int i=0;i<53;i++) {
			if(password[i]<0) {
				check = false; break;
			}
		}
		
		if(check) System.out.print('y');
		else System.out.print('n');
	}
}