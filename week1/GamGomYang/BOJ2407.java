import java.util.Scanner;

import java.util.*;


public class BOJ2407 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);


        int a = scanner.nextInt();

        int b = scanner.nextInt();


        int result =1;


        for(int i=0; i<(a-b);i++){
            result = result*(a-i); 
        }

        System.out.println(result);

        
    }
    
}
