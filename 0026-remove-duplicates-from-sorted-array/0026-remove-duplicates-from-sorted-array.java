class Solution {
    public int removeDuplicates(int[] nums) {
        int st =0; int end = 0; int cnt =0;
        while(st<nums.length){
          while(end<nums.length && nums[st]==nums[end])end++;

          if(end == nums.length)break;
          st++;
          nums[st] = nums[end];
          cnt++;
        }
       return cnt+1;
    }
}