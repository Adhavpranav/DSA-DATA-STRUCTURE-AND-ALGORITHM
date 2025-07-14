//Find the Second Largest Element in an Array
public class secondlarge {
    public static void main(String[] args) {
        int arr[]={50, 50, 50};
        int first_large=Integer.MIN_VALUE;
        int second_large=Integer.MIN_VALUE;
        int i=0;
        while(i<arr.length){
            if(arr[i]>first_large){
                second_large=first_large;
                first_large=arr[i];
            }else if(arr[i]>second_large || first_large==second_large){
                second_large=arr[i];
            }
            i++;
        }
        if(first_large==second_large){
            System.out.println("SECOND LARGE NOT FOUND");
        }else
        System.out.println("SECOND LARGE NUMBER:"+second_large);

    }
}
