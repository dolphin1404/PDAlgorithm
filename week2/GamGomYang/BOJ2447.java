import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.*;

public class BOJ2447 {

    static char[][] stared;

    public static void star(int x, int y, int N, boolean blank) {
        if (blank) {
            for (int i = x; i < x + N; i++) {
                for (int j = y; j < y + N; j++) {
                    stared[i][j] = ' ';
                }
            }
            return;
        }

        if (N == 1) {
            stared[x][y] = '*';
            return;
        }

        int size = N / 3;
        int count = 0;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                count++;
                if (count == 5) {
                    star(x + i * size, y + j * size, size, true);
                } else {
                    star(x + i * size, y + j * size, size, false);
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        stared = new char[N][N];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                stared[i][j] = ' ';
            }
        }

        star(0, 0, N, false);

        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                sb.append(stared[i][j]);
            }
            sb.append('\n');
        }

        System.out.print(sb);
    }
}
