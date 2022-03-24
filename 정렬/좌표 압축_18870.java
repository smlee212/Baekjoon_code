import java.util.*;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException; 

class Main {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringBuilder sb = new StringBuilder();
  
    static int n;
    static int[] arr, sortedArr;
    static HashMap<Integer,Integer> rank = new HashMap<>();
    
	public static void main(String[] args) throws IOException  {
		n = Integer.parseInt(br.readLine());
		
		arr = new int[n];
		sortedArr = new int[n];
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++) {
			arr[i] = sortedArr[i] = Integer.parseInt(st.nextToken());
		}
		
		Arrays.sort(sortedArr);
		
		for(int i=0, rankIndex=0;i<n;i++) {
			if(!rank.containsKey(sortedArr[i])) {
				rank.put(sortedArr[i], rankIndex++);
			}
		}
		
		for(int i=0;i<n;i++) {
			sb.append(rank.get(arr[i])+" ");
		}
		
		bw.write(sb.toString());
		bw.close();
		br.close();
	}
}