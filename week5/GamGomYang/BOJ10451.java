import java.util.*;

public class BOJ10451{
    static int cnt;
    static int[] graph;
    static boolean[] visited;
    
    public static void bfs(int index){
        Queue<Integer> que = new LinkedList<>(); 
        que.offer(index);
        visited[index] = true;
        
        while(!que.isEmpty()){
            int cur = que.poll();
            if(!visited[graph[cur]]){
                visited[graph[cur]] = true;
                que.offer(graph[cur]);
            }else{
                cnt++;
                break;
            }
        }
    }
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int T = sc.nextInt();
        for(int tc=0; tc<T; tc++){
            int N = sc.nextInt();
            
            cnt = 0;
            graph = new int[N+1];
            visited = new boolean[N+1];
            
            for(int i=1; i<=N; i++) graph[i] = sc.nextInt();
            for(int i=1; i<=N; i++){
                if(!visited[i]){
                    bfs(i);
                }
            }
            System.out.println(cnt);
        }
    }
}