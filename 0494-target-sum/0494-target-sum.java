class Solution {
    int cnt = 0;
    void help(int idx, int[] nums, int num , int target){

        if(idx == nums.length && num != target) return;
        if(target == num && idx == nums.length){
            cnt++;
            return;
        }

        help(idx+1,nums,num - nums[idx],target);
        help(idx+1,nums,num + nums[idx],target);
    }
    public int findTargetSumWays(int[] nums, int target) {
        int num = 0;
         help(0,nums,num,target);
         return cnt;
    }
}