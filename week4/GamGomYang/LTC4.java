import java.util.List;
import java.util.Arrays;
import java.util.Scanner;


public class LTC4{
public double findMedianSortedArrays(int [] nums1, int[] nums2){

    int n1_length = nums1.length;
    int n2_length = nums2.length;

    int n = n1_length + n2_length;



    int[] result = new int[n];


    for(int i=0; i< n1_length;i++){
       result[i]= nums1[i];
    }

    for(int j =0 ; j< n2_length;j++){
        result[j+n1_length]=nums2[j];
    }


    Arrays.sort(result);
     
    double sum =0;

    if(n%2 == 0){
         sum =(double) (result[n/2]+result[(n-1)/2])/2;
    }
    else{
        sum = (double)(result[n/2]);
    }

    return sum;


}

}