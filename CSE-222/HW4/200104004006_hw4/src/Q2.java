public class Q2 {

    /**
     * Given an array of integers and two integers n1 and n2, find all the items between n1 and n2 (inclusive) and print
     * them
     *
     * @param arr the array to search
     * @param n1 The first number to search for
     * @param n2 The number you want to find the index of.
     */
    public static void itemsBetween(int arr[], int n1, int n2){
        int indexn1 = binarySearch(arr, n1,0, arr.length);
        int indexn2 = binarySearch(arr, n2,0, arr.length);

        if(indexn1 == -1 || indexn2 == -1){
            System.out.println("Items couldn't find");
            return;
        }


        if(indexn1>indexn2){
            System.out.print("Items between ");
            for (int i = indexn2+1;i<indexn1;i++)
                System.out.print(arr[i] + " ");
        }
        else{
            System.out.print("Items between ");
            for (int i = indexn1+1;i<indexn2;i++)
                System.out.print(arr[i] + " ");
        }
    }





    /**
     * Given a sorted array, find the index of the target value
     *
     * @param nums the array of integers
     * @param target the value you're searching for
     * @param first The index of the first element in the array.
     * @param last The last index of the array.
     * @return The index of the target number.
     */
    private static int binarySearch(int[] nums, int target, int first, int last){
        int middle;

        if(first >= last ){
            return -1;
        }
        middle = (first + last) / 2;
        if(nums[middle] == target){
            return middle;
        }
        if(nums[middle] > target){
            return binarySearch(nums, target, first, middle-1);
        }
        return binarySearch(nums, target, middle+1, last);
    }


    public static void main(String[] args) {
        int arr[] = {1,2,3,4,5,6,7,8,9,10};

        itemsBetween(arr,3,7);
    }

}



