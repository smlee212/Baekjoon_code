import java.util.*;

class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(), m = sc.nextInt();
		String res = "";
		int hd = 0;
		
		String[] dna = new String[n];
		for(int i=0;i<n;i++) dna[i] = sc.next();
		
		for(int i=0;i<m;i++) {	
			int[] acgt = new int[4];
			for(int j=0;j<n;j++) {
				char ch = dna[j].charAt(i);
				
				switch(ch){
					case 'A':
						acgt[0]++;
						break;
					case 'C':
						acgt[1]++;
						break;
					case 'G':
						acgt[2]++;
						break;
					case 'T':
						acgt[3]++;
						break;
				}
			}
			int idx = 0, max = 0;
			for(int k=0;k<4;k++) {
				if(acgt[k]>max) {
					max = acgt[k];
					idx = k;
				}
			}
			
			switch(idx) {
			case 0:
				res += 'A';
				break;
			case 1:
				res += 'C';
				break;
			case 2:
				res += 'G';
				break;
			case 3:
				res += 'T';
				break;
			}
			hd += n - max;
		}
		
		System.out.println(res);
		System.out.println(hd);	
	}
}