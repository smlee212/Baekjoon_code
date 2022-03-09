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
    
	public static void main(String[] args) throws IOException  {
		int t = Integer.parseInt(br.readLine());
		ArrayList<Integer> arr = new ArrayList<Integer>();
		
		while(t-->0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String op = st.nextToken();
            
            switch(op) {
            case "push":
                int num = Integer.parseInt(st.nextToken());
                arr.add(num);
            	break;
            case "pop":
            	if(arr.isEmpty()){
            		sb.append("-1\n");
            	}
            	else{
            		sb.append(arr.get(arr.size()-1)+"\n");
                	arr.remove(arr.size()-1);
            	}
            	break;
            case "size":
            	sb.append(arr.size()+"\n");
            	break;
            case "empty":
            	sb.append(arr.size()>0 ? "0\n" : "1\n");
            	break;
            case "top":
	            if(arr.isEmpty()){
	        		sb.append("-1\n");
	        	}
	        	else{
	        		sb.append(arr.get(arr.size()-1)+"\n");
	        	}
            	break;
            }
			
		}
        bw.write(sb.toString());
        bw.close();
        br.close();
	}
}