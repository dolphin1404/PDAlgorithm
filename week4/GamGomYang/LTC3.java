import java.util.HashSet;
import java.util.Scanner;


public class LTC3{

    public int lengthOfLongestSubstring(String s){

        int n = s.length();
        int left =0;
        int result =0;
        HashSet<Character> hashset = new HashSet<>();


        for(int right =0; right < n ; right++){

            while(hashset.contains(s.charAt(right))){
                hashset.remove(s.charAt(left));
                left++;

            }

            hashset.add(s.charAt(right));

            result =Math.max(result, right -left+1);


        }

        return result;
    }


}