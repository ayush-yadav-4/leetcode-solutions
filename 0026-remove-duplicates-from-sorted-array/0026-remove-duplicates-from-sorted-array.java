class Solution {
    public int removeDuplicates(int[] nums) {
        int[] arr = new int[nums.length];
         int idx = 1;
         arr[0] = nums[0];
        for(int i=0;i<nums.length;i++){
          if(i>0 && nums[i] != nums[i-1])arr[idx++] = nums[i];
          
        }

        System.arraycopy(arr,0,nums,0,nums.length);

        return idx;
    }
}