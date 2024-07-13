import java.util.Scanner;
import java.util.Stack;

public class PostfixCalculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int number = scanner.nextInt();
        scanner.nextLine();

        String sik = scanner.nextLine();

        int[] sikList = new int[number];

        for (int i = 0; i < number; i++) {
            sikList[i] = scanner.nextInt();
        }

        Stack<Double> stack = new Stack<>();

        for (char ch : sik.toCharArray()) {
            if ('A' <= ch && ch <= 'Z') {
                stack.push((double) sikList[ch - 'A']);
            } else {
                double str2 = stack.pop();
                double str1 = stack.pop();

                switch (ch) {
                    case '+':
                        stack.push(str1 + str2);
                        break;
                    case '-':
                        stack.push(str1 - str2);
                        break;
                    case '/':
                        stack.push(str1 / str2);
                        break;
                    case '*':
                        stack.push(str1 * str2);
                        break;
                }
            }
        }

        System.out.printf("%.2f", stack.pop());
    }
}
