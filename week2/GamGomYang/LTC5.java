import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;


public class LTC5{

     static int left;
     static int maxlen;
    

    public void extendPalindrome(String s, int j, int k){


        while(j>= 0 && k< s.length() && s.charAt(j) == s.charAt(k)){

            j--;
            k++;
        }

        if(maxlen < k-j-1){
            left = j+1;
            maxlen= k-j-1;
 
        }

    }

    public String longestPalindrome(String s){
        int len = s.length();

        if(len <2){
            return s;
        }

        left =0;
        maxlen =0;

        for(int i=0; i<len-1 ; i++){
            extendPalindrome(s, i, i+1);
            extendPalindrome(s, i, i+2);
            
        }

        return s.substring(left,left+maxlen);

        
    }

    
}