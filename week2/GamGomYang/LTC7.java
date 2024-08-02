

public class LTC7{

    public int reverse(int x){


        int max = Integer.MAX_VALUE;
        int min = Integer.MIN_VALUE;
        int result =0;



        while (x!=0){

            int num = x%10;
            x = x/10;

            if(result > max/10 || (result == max/10 && num > 7 )){
                return 0;
            }
            else if(result < min/10 || (result == min/10 && num<-8)){

                return 0;
            }
            

 

            result = result*10+num;

        }


        return result;
    }
}