import java.util.*;
import java.io.*;




class leetcode6 {
    public String convert(String s, int numRows) {

        //예외처리
        if(numRows == 1 || s.length()<= numRows){
            return s;

        }

        //StringBuilder를 담을 배열을 선언
        //StringBuilder객체 생성되어지지 않은 상태

        StringBuilder[] rows = new StringBuilder[numRows];
        /*
         * 
         * StringBuilder -> java문자열 을 다룰때 자주 쓰임
         * String  =  immutable 자료형( 불변 )
         * StringBuilder = mutable 자료형( 가변 )
         * String을 자주 수정 삭제 할때 유용하다.
         * 
         * 
         * 
         */

        for(int i=0; i< numRows; i++ ){

            rows[i] = new StringBuilder();
        }

        int currentRow =0;
        boolean down = false;

        for(char c : s.toCharArray()){
            rows[currentRow].append(c);

            if(currentRow == 0 || currentRow == numRows -1 ){

                down = !down;

            }

            currentRow += down ? 1:-1;



        }


        StringBuilder result = new StringBuilder();


        for(StringBuilder row: rows){
            result.append(row);
        }


        return result.toString();




        
    }
}