import java.util.Scanner;
import java.util.Arrays;
import java.math.*;


public class Solution{


    public int maxProfit(int[] prices){

        int Max =0;
        int minprice = prices[0];


        for(int price: prices){

            minprice = Math.min(minprice,price);
            Max = Math.max(Max, price- minprice);


        }

        return Max;
    }
}