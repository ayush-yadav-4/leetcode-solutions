class Solution {
    public int[] concatWithReverse(int[] nums) {
        int[] arr = new int[2*nums.length];
       int n = 2* nums.length;
        for(int i=0;i<nums.length;i++){
         arr[i] = nums[i];
         arr[n-i-1] = nums[i];
        }
        return arr;
    }
}