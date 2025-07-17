class Solution {


    boolean check(int[] nums, int k,int mid){
        int last = nums[0],p =1;
       for(int i=1;i<nums.length;i++){
        if(nums[i] > mid) return false;
          if((last + nums[i]) > mid){
            p++;
            last = nums[i];
          }
          else{
            last += nums[i];
          }
       }
       if(p<=k) return true;
       return false;
    }
    public int splitArray(int[] nums, int k) {
         
         int st = Integer.MIN_VALUE,end = 0,ans = 0,mid = 0;
         for(int i=0;i<nums.length;i++){
             st = Math.max(st,nums[i]);
             end += nums[i];
         }

         while(st<=end){
             mid = st + (end-st)/2;
             if(check(nums,k,mid)){
                 ans = mid;
                 end = mid -1;
             }
             else{
                st = mid +1; 
             }
         }
         return ans;
    }
}