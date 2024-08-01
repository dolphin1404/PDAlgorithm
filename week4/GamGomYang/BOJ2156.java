import java.util.Scanner;
 
public class BOJ2156 {
	
	static Integer[] dp;
	static int[] arr;
    
	public static void main(String[] args) {
    
		Scanner in = new Scanner(System.in);
		
		int N = in.nextInt();
		
		dp = new Integer[N + 1];
		arr = new int[N + 1];
		
		for(int i = 1; i < N + 1; i++) {
			arr[i] = in.nextInt();
		}
 
		dp[0] = 0;
		dp[1] = arr[1];

		if(N > 1) {
			dp[2] = arr[1] + arr[2];
		}
		
		System.out.println(recur(N));
	}
	
	static int recur(int N) {
		
		if(dp[N] == null) {
			dp[N] = Math.max(Math.max(recur(N - 2), recur(N - 3) + arr[N - 1]) + arr[N], recur(N - 1));
		}
		
		return dp[N];
	}
}