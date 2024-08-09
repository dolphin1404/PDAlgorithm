import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.util.Stack;


/*
 * 
 * 
 * 수도 코드
 * 문자열을 문자 배열로 나타내야함
 * 1. 만약 ( 이 입력되었다면 스택에 푸시
 * 2. ) 라면 스택에서 팝하여 () 규칙이 맞는지 확인
 */


public class Solution{


    public boolean solution(String s){
        boolean answer = true;
        int size =s.length();

        


        Stack<Character> stack = new Stack<>();


        for(int i=0 ; i< size ; i++){
            char c = s.charAt(i);


            if(c=='('){
                stack.push(c);
            }
            else if( c == ')'){
                 if(stack.isEmpty()||stack.pop() == 'c'){
                    return false;
                 }
            }
            
        }
        return stack.isEmpty();



        




    }
}
