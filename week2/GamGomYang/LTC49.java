import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;


public class LTC49{


    public List<List<String>> groupAnagrams(String[] strs){
        
        Map<String, List<String>> result = new HashMap<>();

        for(String s: strs){
            char[] chars = s.toCharArray();


            Arrays.sort(chars);

            String key = String.valueOf(chars);

            if(!result.containsKey(key)){
                result.put(key, new ArrayList<>());

                
            }

            result.get(key).add(s);

        }
        return new ArrayList<>(result.values());

        
    }

 



}