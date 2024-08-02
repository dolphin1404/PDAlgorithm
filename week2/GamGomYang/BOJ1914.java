import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class BOJ1914 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

  
        int n = Integer.parseInt(br.readLine());

   
        BigInteger count = new BigInteger("2");
        System.out.println(count.pow(n).subtract(BigInteger.ONE));

    
        if (n <= 20) { 
            hanoi(n, 1, 3, 2);
        }
    }


    public static void hanoi(int n, int start, int goal, int assist) {
        if (n == 1) {
            System.out.println(start + " " + goal);
            return;
        }

   
        hanoi(n - 1, start, assist, goal);

        System.out.println(start + " " + goal);

        hanoi(n - 1, assist, goal, start);
    }
}
