import java.util.*;

public class LTC819{

public String mostCommonWord(String p , String[] banned){

    Set<String> ban = new HashSet<>(Arrays.asList(banned));

    Map<String, Integer> counts = new HashMap();

    String[] words = p.replaceAll("[^a-zA-Z]", " ").toLowerCase().split(" ");

    for(String w: words){
        if(!ban.contains(w)){
            counts.put(w, counts.getOrDefault(w, 0)+1);
        }
    }

    return Collections.max(counts.entrySet(),Map.Entry.comparingByValue()).getKey();
}

}