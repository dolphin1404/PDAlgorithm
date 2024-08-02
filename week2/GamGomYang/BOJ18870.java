import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ18870 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int count = 0;
        StringTokenizer st = new StringTokenizer(br.readLine()," ");
        int[] nums = new int[N];
        for (int i = 0; i < N; i++) {
        	nums[i] = Integer.parseInt(st.nextToken()); 
        }
        int[] origin = nums.clone();
        Arrays.sort(nums);
        StringBuilder sb = new StringBuilder();
        HashMap<Integer, Integer> x = new HashMap<>();

        
        for (int i = 0; i< N; i++) {
        	if (!x.containsKey(nums[i])) {
        		x.put(nums[i], count++);
        	}
        }
        for (int i = 0; i < N; i++) {
        	sb.append(x.get(origin[i])).append(" ");
        }
        System.out.println(sb);
    }
}