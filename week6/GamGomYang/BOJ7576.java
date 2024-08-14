import java.io.*;
import java.util.*;

public class Main {
    static int N; // 세로 칸의 수
    static int M; // 가로 칸의 수
    static int[][] graph; // 그래프배열
    static boolean[][] visited; //방문한 자리
    static int count = 0; // 최소 날짜
    static int[] dx = {0, 0, 1, -1};
    static int[] dy = {1, -1, 0, 0};
    static Queue<int[]> q = new LinkedList<>();

    public static void main(String[] args) throws Exception {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");


        M = Integer.parseInt(st.nextToken()); // 세로 칸  초기화
        N = Integer.parseInt(st.nextToken()); // 가로 칸 초기화

        // 그래프 초기화
        graph = new int[N][M];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            for (int j = 0; j < M; j++) {
                graph[i][j] = Integer.parseInt(st.nextToken());
                if (graph[i][j] == 1) { // 1일 경우 큐에 삽입
                    q.add(new int[]{i, j});
                }
            }
        }
        System.out.println(bfs());
    }

    public static int bfs() {
        while (!q.isEmpty()) { // 큐가 다 빌때까지 실행
            int[] tmp = q.poll();
            int x = tmp[0];
            int y = tmp[1];
            // 4방 탐색
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                //그래프 범위 안에 있을 경우
                if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
                    if (graph[nx][ny] == 0) {
                        q.add(new int[]{nx, ny});
                        graph[nx][ny] = graph[x][y] + 1; // 새로 추가된 곳은 원래 있던 수 + 1
                        // 그 이유는 날짜를 세기 위해
                    }
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (graph[i][j] == 0) { // 그래프안에 0 이 존재하면 답은 -1
                    return -1;
                }
                // 그래프의 날짜중에 가장 큰 수를 찾으면 그것이 최종날짜
                count = Math.max(count, graph[i][j]);
            }
        }

        // 저장될 때부터 모든 토마토가 익어익는상태라면
        if (count == 1) {
            return 0;
        } else { // 아닐 경우 최종날짜 - 1 출력
            return count-1;
        }
    }}