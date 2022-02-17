import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt();
		for(int i=1;i<=k;i++) {
			int n = sc.nextInt();
			int Max, Min;
			int[] score = new int[n];
			for(int j=0;j<n;j++) score[j] = sc.nextInt();
			Arrays.sort(score);
			Max = score[n-1];
			Min = score[0];
			int Gap = 0;
			for(int j=0;j<n-1;j++)
				Gap = score[j+1] - score[j] > Gap ? score[j+1] - score[j] : Gap;
			
			System.out.printf("Class %d\n",i);
			System.out.printf("Max %d, Min %d, Largest gap %d\n",Max,Min,Gap);
		}
	}
}