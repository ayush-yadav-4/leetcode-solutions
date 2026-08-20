class Solution {

   
    public List<Integer> largestDivisibleSubset(int[] nums) {
         int[] dp = new int[nums.length];
          int[] hash = new int[nums.length];
         Arrays.fill(dp,1);
          Arrays.fill(hash,-1);
          int maxi =0;
         Arrays.sort(nums);
        for(int i=1;i<nums.length;i++){
          for(int j = 0;j<i;j++){
             if(nums[i]%nums[j]==0 && dp[i] < (dp[j] + 1)){
                dp[i] = dp[j] + 1;
                hash[i] = j;
                maxi = Math.max(maxi, dp[i]);
             }
          }
        }
        List<Integer>ans = new ArrayList<>();
        for(int i=0;i<nums.length;i++){
           if(maxi == dp[i]){
            int idx = i;
            while(idx>=0){
                ans.add(nums[idx]);
                idx = hash[idx];
            }
            break;
           }
        }
        if(ans.size() == 0)ans.add(nums[0]);
        Collections.sort(ans);
        return ans;
    }
}