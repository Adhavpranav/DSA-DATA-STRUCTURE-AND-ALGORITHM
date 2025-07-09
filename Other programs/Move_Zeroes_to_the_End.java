/*
Given an array of integers,
move all the zeroes to the end of the array in-place (without using extra space),
while maintaining the relative order of non-zero elements.
*/

import java.util.*;
public class zero {
    public static void main(String[] args) {
        int arr[]={0, 1, 0, 3, 12};
        int index=0;
        for(int i=0;i<arr.length;i++){
            if(arr[i]!=0){
                arr[index++]=arr[i];
            }
        }
        while(index<arr.length){
            arr[index++]=0;
        }
                System.out.println(Arrays.toString(arr));

    }
}
