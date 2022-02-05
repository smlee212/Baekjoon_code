import java.util.Scanner;
import java.util.Arrays;

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int arr[] = {sc.nextInt(), sc.nextInt(), sc.nextInt()};
    sc.close();
    
    Arrays.sort(arr);
    
    System.out.println(arr[1]);
  }
}