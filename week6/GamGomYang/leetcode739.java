import java.util.List;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Stack;
import java.util.Scanner;

/*
 * 
 * 매일의 온도리스트 temperatures를 입력받아서, 더 따뜻한 날씨를 위해서는 며칠을 더기다려야 하는지 출력
 * 
 * solution: 스택값 비교
 * 
 * 현재의 인덱스를 계속 스택에 쌓아두다가, 이전보다 상승하는 지점에서 현재온도와 스택에 쌓아둔
 * 인덱스 지접의 온도차이를 비교해서, 더 높다면 stack.pop을 하여서 현재 스택의 인택스와 온도차이를 비교하여
 * 업데이트 함
 * 
 * 수도 코드
 * 1. 현재 인덱스를 stack에 push한다.
 * 2. 만약 이전 온도가 현재 인덱스의 온도보다 높다면 
 * -> stack.pop을 하여서 현재 인덱스와 pop인덱스의 차이를 비교한다.
 * 3. 예외 처리 -> stack.isEmpty일 경우 예외 처리
 * 4. result return
 * 
 * 
 * 
 * 
*/

class leetcode739 {
    public int[] dailyTemperatures(int[] temperatures) {


        int[] result = new int[temperatures.length];



        Deque<Integer> stack = new ArrayDeque<>();

        for(int i=0 ;i< temperatures.length ; i++){


            while(!stack.isEmpty()&& temperatures[i]>temperatures[stack.peek()]){

                int last = stack.pop();


                result[last] = i-last;

            }


            stack.push(i);

        }

        return result;
        
    }
}