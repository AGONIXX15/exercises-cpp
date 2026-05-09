
import java.util.Scanner;


public class Main {
  
  public static void main(String[] args) {
    

    var sc = new Scanner(System.in);
    int t = sc.nextInt();

    while(t != -1) {
      
      int n = sc.nextInt();
      int k = sc.nextInt();
      //  n - k * 7


      if(k * 7 < n) {

        System.out.println((int)Math.ceil((n - k * 7) / 14.));
      } else {
        System.out.println("0");
      }

    }

    sc.close();
    
  }
}
