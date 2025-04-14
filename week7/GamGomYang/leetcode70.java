package DynamicProgramming;
import java.util.Scanner;
import java.util.List;
import java.util.Stack;




public class leetcode70{

    public int climbStairs(int n) {

        if(n<=2){
            return n;
        }

        int[] stepsum = new int[n+1];

        stepsum[1] =1;
        stepsum[2]=2;

        return recursive(n,stepsum);


            
        }

        int recursive(int n,  int [] stepsum){

            if(stepsum[n]==0){
                stepsum[n] = recursive(n-1, stepsum)+recursive(n-2,stepsum);
            }

            return stepsum[n];
        }
    

}