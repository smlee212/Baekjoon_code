import java.util.*;

class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		HashMap<String,Integer> book = new HashMap<String,Integer>();
		
		for(int i=0,j=0;i<n;i++) {
			String str = sc.next();
			if(book.containsKey(str)) {
				book.replace(str, book.get(str)+1);
			}
			else {
				book.put(str, 1);
			}
		}
		
		int maxCnt = 0;
		for(String str : book.keySet()) {
			maxCnt = Math.max(maxCnt, book.get(str));
		}
		ArrayList<String> sortBook = new ArrayList<String>(book.keySet());
		Collections.sort(sortBook);
		for(String str : sortBook) {
			if(book.get(str)==maxCnt) {
				System.out.print(str);
				break;
			}
		}
	}
}