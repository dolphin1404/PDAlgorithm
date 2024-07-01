import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class BOJ1978 {

    public static boolean primeSolution(int num) {
        if (num <= 1) {
            return false;
        }
        for (int i = 2; i <= num; i++) { 
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    public static int primeCounter(List<Integer> numbers) {
        int counter = 0;
        for (int number : numbers) {
            if (primeSolution(number)) {
                counter++;
            }
        }
        return counter;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        List<Integer> numbers = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            numbers.add(scanner.nextInt());
        }

        int counter = primeCounter(numbers);

        System.out.println(counter);
    }
}
