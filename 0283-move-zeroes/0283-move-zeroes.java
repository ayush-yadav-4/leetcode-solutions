class Solution {
    public void moveZeroes(int[] nums) {
       
       for(int i=0;i<nums.length;i++){
          if(nums[i] == 0){
            int idx = i;
            while(idx<nums.length && nums[idx] == 0){
             idx++;
            }
            if(idx < nums.length && idx != i){
            nums[i] = nums[idx];
            nums[idx] = 0;
            }
          }

       }
    }
}