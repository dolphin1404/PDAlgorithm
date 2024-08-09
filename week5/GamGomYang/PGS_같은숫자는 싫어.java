import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.util.Stack;
import java.util.HashSet;
import java.util.Deque;

/*
 * 수도 코드
 * 1: 해시 셋에 해당 숫자를 넣는다.
 * 만약 해시셋에 숫자가 없다면 -> 스택 푸시
 * 해시셋에 숫자가 있다면 -> 건너뛰기
 * 
 * 2. arr.length만큼 수행했다면 해당 스택에 있는 값 팝 출력
 * 
 */
/* 

public class Solution{

    public int[] solution(int[] arr){
        //1. 해시셋 스택 구현

        

       Stack <Integer> stack = new Stack<>();


       HashSet<Integer> hashset = new HashSet<>();


       for(int i =0 ; i< arr.length ; i++){

        if(!hashset.contains(arr[i])){
            hashset.add(arr[i]);
            stack.push(arr[i]);

        }}

        int[] answer = new int[stack.size];

        for(int i=0; i<answer.length;i++){

           answer[i] = stack.pop();
        }




       return answer;






    }


    
}*/



public classs Solution{
    public int[] solution(int[] arr){

        Stack<Integer> stack = new Stack<>();
        int check_number=-99999;

        for (int i = 0; i < arr.length; i++) {
            if (check_number != arr[i]) {
                stack.push(arr[i]);
            }
            check_number = arr[i];
        }

        int[] answer = new int[stack.size()];

        for (int i = stack.size() - 1; i >= 0; i--) {
            answer[i] = stack.pop();
        }

        return answer;
    }
}
