class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        if(nums.length == 0) return 0;
        if(nums.length == 1) return nums[0];
        int i = 0, j = 0 , ans = 0;
       
        while(i < nums.length){
           if(nums[i] == 0){
            j = i + 1;
            
           }
           if(nums[i] == 1)ans = Math.max(ans, (i - j + 1));
           i++;
        }
        return ans;
    }
}