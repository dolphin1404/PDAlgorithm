import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Map;


public class LTC241{


    public boolean isAnagram(String s, String t){

        char[] result1 = s.toCharArray();
        Arrays.sort(result1);

        char[] result2 = t.toCharArray();
        Arrays.sort(result2);


        if(Arrays.equals(result1,result2)){
            return true;
        }
        else{
            return false;
        }

        



    }
}