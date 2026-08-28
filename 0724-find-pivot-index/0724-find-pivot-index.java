class Solution {
    public int pivotIndex(int[] nums) {
        
        int[] suf = new int[nums.length];
        int[] pre = new int[nums.length];
        int sum = 0; int total = 0;
        pre[0] = nums[0];
        suf[nums.length-1] = nums[nums.length-1];
        for(int i=1;i<nums.length;i++){
            int j = nums.length - i - 1;
         pre[i] = pre[i-1] + nums[i];
         suf[j] = suf[j+1] + nums[j];
         
        }
        for(int i=0;i<nums.length;i++){
            if(pre[i] == suf[i]) return i;
        }
        
         
        return -1;
    }
}