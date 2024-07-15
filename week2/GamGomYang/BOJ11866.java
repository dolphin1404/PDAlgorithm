import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class BOJ11866 {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
    
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        scanner.close();


        List<Integer> number = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            number.add(i);
        }

        List<Integer> result = new ArrayList<>();
        int index = 0;


        while (!number.isEmpty()) {
            index = (index + k - 1) % number.size(); 
            result.add(number.remove(index));
        }

  
        System.out.print("<");
        for (int i = 0; i < result.size(); i++) {
            if (i != result.size() - 1) {
                System.out.print(result.get(i) + ", ");
            } else {
                System.out.print(result.get(i));
            }
        }
        System.out.println(">");
    }
}
