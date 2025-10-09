class Solution {
    boolean helper(int[] arr , int mid ,int maxi){
        int ans = 0;
       for(int i=0;i<arr.length;i++){
         if(arr[i] % mid == 0){
           ans += arr[i]/mid;
         }
         else{
            ans += (arr[i]/mid) + 1;
         }
       }
       if(ans > maxi) return false;
       return true;
    }
    public int smallestDivisor(int[] nums, int threshold) {
        
        int st = 1, end = Integer.MAX_VALUE;
       int mid = 0,ans = 0;
        while(st<=end){
            mid = st + (end - st)/2;
            if(helper(nums,mid,threshold)){
              ans = mid;
              end = mid-1;
            }
            else{
              st = mid+1;
            }

        }

        return ans;
    }
}