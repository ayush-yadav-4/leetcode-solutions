class Solution {
    public int findMin(int[] arr) {
        int mini = Integer.MAX_VALUE;
         int idx = 0;
         int st =0,end = arr.length -1;
        while(st<= end){
         int mid = st + (end - st)/2;

         if(arr[st] <= arr[mid]){
            if(mini > arr[st]){
                mini = arr[st];
                
            }
            st = mid+1;
         }
         else{
             if(mini > arr[mid]){
                mini = arr[mid];
                
             }
             end = mid-1;
         }
        }
        return mini;
    }
}