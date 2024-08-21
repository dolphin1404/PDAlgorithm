import java.util.Scanner;
import java.util.List;
import java.util.Arrays;
import java.util.ArrayList;


public class Solution{
    public List<List<Integer>> generate(int numRows) {

    List<List<Integer>> result = new ArrayList();
     int n = numRows;


     for(int i=0 ; i<n ;i++){
        List<Integer> row = new ArrayList();
        row.add(1);


        for(int j=1; j<i;j++){

            List<Integer> prerow = result.get(i-1);
            int value= prerow.get(j-1)+ prerow.get(j);

            row.add(value);


        }
        if(i>0){
            row.add(1);
        }


        result.add(row);
     }


     return result;


    

    }



}

