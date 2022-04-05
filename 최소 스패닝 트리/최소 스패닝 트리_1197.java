import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.StringTokenizer;

class Main {
    static int v, e; 
    static int res = 0;
    static int[] parent;
    
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuffer sb = new StringBuffer();
		
		StringTokenizer st = new StringTokenizer(br.readLine());		
		v = Integer.parseInt(st.nextToken());
		e = Integer.parseInt(st.nextToken());
		
		ArrayList<Edge> edges = new ArrayList<>();
		
		// edge 입력
		for(int i=0;i<e;i++) {
			st = new StringTokenizer(br.readLine());
			int v1 = Integer.parseInt(st.nextToken());
			int v2 = Integer.parseInt(st.nextToken());
			int cost = Integer.parseInt(st.nextToken());
			
			edges.add(new Edge(v1,v2,cost));
		}
		
		// cost 순으로 정렬
		edges.sort(new Comparator<Edge>(){
			@Override
			public int compare(Edge o1, Edge o2) {
				return Integer.compare(o1.cost, o2.cost);
			}			
		});
		
		// 사이클 테이블 초기화
		parent = new int[v+1];
		for(int i=1;i<=v;i++) {
			parent[i] = i;
		}
		
		// 연결된 두 노드의 부모를 확인
		// 부모가 같지 않으면 union 후 cost 더함
		// 부모가 같다면 사이클이 생기며 cost도 최소가 아니므로 건너뜀
		for(int i=0;i<e;i++) {
			Edge edge = edges.get(i);
			if(!isSameParent(edge.v1, edge.v2)) {
				union(edge.v1, edge.v2);
				res += edge.cost;
			}			
		}
		
		bw.write(res+"\n");
		br.close();
		bw.flush();
		bw.close();
	}	
	
	public static int find(int v) {
		if(parent[v] == v) 
			return v;
		else 
			return parent[v] = find(parent[v]);
	}
	
	public static boolean isSameParent(int v1, int v2) {
		v1 = find(v1);
		v2 = find(v2);
		
		if(v1 == v2) 
			return true;
		else
			return false;
	}
	
	public static void union(int v1, int v2) {
		v1 = find(v1);
		v2 = find(v2);
		
		if(v1 != v2) 
			parent[v2] = v1;
	}
}

class Edge{
	int v1, v2, cost;
	
	Edge(int v1, int v2, int cost){
		this.v1 = v1;
		this.v2 = v2;
		this.cost = cost;
	}	
}