class Solution {
    int cnt = 0;
    int help(int idx, int[] nums, int num , int target){

        if(idx == nums.length && num != target) return 0;
        if(target == num && idx == nums.length){
            
            return 1;
        }

       
        return help(idx+1,nums,num - nums[idx],target)+
        help(idx+1,nums,num + nums[idx],target);
    }
    public int findTargetSumWays(int[] nums, int target) {
        int num = 0;
        return help(0,nums,num,target);
       
    }
}