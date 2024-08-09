import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;

public class leetcode438{

    public List<Integer> findAnagrams(String s , String p ){

        List<Integer> result = new ArrayList<>();
        if(s.length()<p.length()){
            return result;
        }

        HashMap<Character, Integer> p_count = new HashMap<>();

           for(char c : p.toCharArray()){
            p_count.put(c, p_count.getOrDefault(c,0)+1);
           }

        HashMap<Character, Integer > s_count = new HashMap<>();


        int p_length = p.length();
        int s_length = s.length();


        for(int i=0; i< s.length(); i++){

            char c =s.charAt(i);
            s_count.put(c,s_count.getOrDefault(c,0)+1);
            

            if(i>= p_length){
                char removeChar = s.charAt(i - p_length);
                if(s_count.get(removeChar)==1){
                    s_count.remove(removeChar);
                }


                else{
                    s_count.put(removeChar, s_count.get(removeChar)-1); }               }


            

            if(p_count.equals(s_count)){
              result.add(i-p_length+1);

            }}

            return result;


        }



    } 
