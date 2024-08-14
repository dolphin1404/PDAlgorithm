import java.util.*;
import java.io.*;


class Solution {
    public int numOfPairs(String[] nums, String target) {

        if(nums.length == 1 ){
            return 0;
        }

        String result;
        int count =0;

        int number = nums.length;
        
        for(int i=0 ; i< number; i++ ){

            for(int j =0 ; j< number; j++ ){

                if(j == i){

                    continue;
                }

                result = nums[i]+nums[j];

                if(result.equals(target)){
                    //java 에서 == 는 참조이다 그러므로 equal을 사용해야함

                    count++;


                }

                
            }


            
        }

        return count;
        
    }
}