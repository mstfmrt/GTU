public class Q3 {

    /**
     * Find the contiguous subarray of an array that sums to a given value
     *
     * @param arr the array to search
     * @param sum the sum we're looking for
     * @param index The index of the array where we are currently searching.
     */
    public static void findConSum(int arr[],int sum, int index){

        int total=0;
        int i = index;
        while(total<=sum){
            if(i +1 > arr.length){
                System.out.println("Contigous subarray didn't find");
                return;
            }
            total += arr[i];
            i++;
            if(total == sum){
                System.out.print("Contiguous sub array is ");
                for(int j=index;j<i;j++)
                    System.out.print(arr[j] + " ");
                return;
            }
            else if(total>sum){
                findConSum(arr,sum,index+1);
                return ;
            }
        }
    }


    public static void main(String[] args) {
        int arr[] = {1,3, 4, 6, 7};
        findConSum(arr,13,0);
    }

}
