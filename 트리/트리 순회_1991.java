import java.util.*;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException; 

class Main {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int n;
    
	public static void main(String[] args) throws IOException  {
		n = Integer.parseInt(br.readLine());
		
		Tree tree = new Tree();
		
		for(int i=0;i<n;i++) {
			char[] c = br.readLine().replace(" ", "").toCharArray();
			tree.createNode(c[0], c[1], c[2]);
		}
		
		tree.preoder(tree.Root);
		System.out.println();
		tree.inoder(tree.Root);
		System.out.println();
		tree.postoder(tree.Root);
		System.out.println();
		
		br.close();
	}
}

class Node{
	char mid;
	Node Left, Right;
	public Node(char mid) {
		this.mid = mid;
	}
}

class Tree{
	Node Root;
	
	public void createNode(char mid, char left, char right) {
		if(Root==null) {
			Root = new Node(mid);
			if(left != '.') Root.Left = new Node(left);
			if(right != '.') Root.Right = new Node(right);
		}
		else {
			searchNode(Root, mid, left, right);
		}
	}
	
	public void searchNode(Node node, char mid, char left, char right) {
		if(node==null) 
			return;
		else if(node.mid==mid) {
			if(left != '.') node.Left = new Node(left);
			if(right != '.') node.Right = new Node(right);
		}
		else {
			searchNode(node.Left, mid, left, right); 
			searchNode(node.Right, mid, left, right);
		}
	}
	
	public void preoder(Node node) {
		System.out.print(node.mid);
		if(node.Left!=null) preoder(node.Left);
		if(node.Right!=null) preoder(node.Right);
	}
	
	public void inoder(Node node) {
		if(node.Left!=null) inoder(node.Left);
		System.out.print(node.mid);
		if(node.Right!=null) inoder(node.Right);
	}
	
	public void postoder(Node node) {
		if(node.Left!=null) postoder(node.Left);
		if(node.Right!=null) postoder(node.Right);
		System.out.print(node.mid);
	}
}