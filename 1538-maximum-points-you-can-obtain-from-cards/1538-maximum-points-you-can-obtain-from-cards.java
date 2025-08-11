class Solution {
    public int maxScore(int[] nums, int k) {
        int sum = 0;
        for(int i=0;i<k;i++){
           sum += nums[i];
        }
        int st = k-1,end = nums.length-1;
        int ans = 0;
        ans = Math.max(ans,sum);
        while(st>=0){
          sum = sum - nums[st];
          sum = sum + nums[end];
          end--; st--;
          ans = Math.max(ans,sum);
        }
        return ans;
    }
}