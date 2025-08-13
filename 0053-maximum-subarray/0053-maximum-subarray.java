class Solution {
    public int maxSubArray(int[] nums) {
        if(nums.length == 1) return nums[0];
         int sum = 0,ans= Integer.MIN_VALUE;
        for(int i=0;i<nums.length;i++){
            sum += nums[i];
           if(sum > ans){
            ans = sum;
           }
            
           if(sum < 0){
            sum = 0;
           }
        }
        return ans;
    }
}