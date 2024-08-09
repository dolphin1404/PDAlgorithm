import java.util.Scanner;
import java.util.List;
import java.util.Arrays;
import java.util.LinkedList;

public class BOJ2156
 {

    /*
     * 수도코드
     * 
     * 예외처리: 포도잔 총 개수가 3개 미만일때 return [];
     * 
     * 
     * 포도주 잔을 선택하면 그 잔에 들어있는 포도주는 모두 마셔야 하고, 마신 후에는 원래 위치에 다시 놓아야 한다.
     *  연속으로 놓여 있는 3잔을 모두 마실 수는 없다.
     * 
     *  -> 문제에서 제시한 규칙: 3가지 경우로 나누어 구현
     * 1.현재 포도주와 이전 포도주를 마시고 전전 포두주는 마시지 않을때. ( wine[i]+wine[i-1]+d[i-3] )
     * 2.현재 포도주와 전전 포도주를 마시고 이전 포도주는 마시지 않을때. ( wine[i]+d[i-2] )
     * 3.현재 포도주를 마시지 않을때. ( d[i-1] ) -> 해당 케이스에 가장큰 max값이 저장되어져 있음.
     * 
     * 
     * 
     */

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int[] wine = new int[n];
        for (int i = 0; i < n; i++) {
            wine[i] = scanner.nextInt();
        }

        int[] d = new int[n];
        if (n > 0) {
            d[0] = wine[0];
        }
        if (n > 1) {
            d[1] = wine[0] + wine[1];
        }
        if (n > 2) {
            d[2] = Math.max(wine[2] + wine[1], Math.max(wine[2] + wine[0], d[1]));
        }

        for (int i = 3; i < n; i++) {
            d[i] = Math.max(d[i - 1], Math.max(d[i - 3] + wine[i - 1] + wine[i], d[i - 2] + wine[i]));
        }

        System.out.println(d[n - 1]);

        scanner.close();
    }
}
