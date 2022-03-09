import java.util.*;

class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str = sc.next();
		String[] buf = new String[3];
		ArrayList<String> res = new ArrayList<>();
		int len = str.length();
		for(int i=1;i<len-1;i++) {
			for(int j=i+1;j<len;j++) {
				buf[0] = str.substring(0,i);
				buf[1] = str.substring(i,j);
				buf[2] = str.substring(j,len);
				
				StringBuffer sb = new StringBuffer();
				
				for(int k=0;k<3;k++) {
					for(int l=buf[k].length()-1;l>=0;l--) {
						sb.append(Character.toString(buf[k].charAt(l)));
					}
				}
				
				res.add(sb.toString());
				sb.setLength(0);
			}
		}
		Collections.sort(res);
		System.out.println(res.get(0));
	}
}