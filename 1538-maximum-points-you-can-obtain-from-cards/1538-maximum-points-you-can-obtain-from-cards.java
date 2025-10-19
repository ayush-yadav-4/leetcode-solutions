class Solution {
    public int maxScore(int[] nums, int k) {
        int ans = 0,sum = 0,end = nums.length-1;
        for(int i=0;i<k;i++){
             sum += nums[i];
        }
        ans = Math.max(ans,sum);
        for(int i=k-1;i>=0;i--){
            sum -= nums[i];
            sum += nums[end--];
            ans = Math.max(sum,ans);
        }
        return ans;
    }
}