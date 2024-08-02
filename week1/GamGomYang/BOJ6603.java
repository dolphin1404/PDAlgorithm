import java.util.Scanner;

public class BOJ6603 {
    static int k;
    static int[] s;
    static int[] number;

    public static void BOJ6603(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            k = scanner.nextInt();
            if (k == 0) {
                break;
            }

            s = new int[k];
            number = new int[6];

            for (int i = 0; i < k; i++) {
                s[i] = scanner.nextInt();
            }

            func_pick(0, 0);
            System.out.println();
        }
    }

    static void func_pick(int index, int count) {
        if (count == 6) {
            for (int i = 0; i < 6; i++) {
                System.out.print(number[i] + " ");
            }
            System.out.println();
            return;
        }

        if (index == k) {
            return;
        }

        for (int i = index; i < k; i++) {
            number[count] = s[i];
            func_pick(i + 1, count + 1);
        }
    }
}
