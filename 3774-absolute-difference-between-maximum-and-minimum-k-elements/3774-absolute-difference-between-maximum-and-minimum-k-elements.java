class Solution {
    public int absDifference(int[] nums, int k) {
        if(k >= nums.length) return 0;
       Arrays.sort(nums);
       int maxi = 0,mini =0;
       for(int i =0;i<k;i++){
        mini += nums[i];
        maxi += nums[nums.length-i-1];
       }
       return Math.abs(maxi - mini);
    }
}