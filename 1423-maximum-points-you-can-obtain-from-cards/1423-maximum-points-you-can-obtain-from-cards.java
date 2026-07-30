class Solution {
    public int maxScore(int[] nums, int k) {
        int sum =0,i=0,j=0,ans=0;
      for( i=0;i<k;i++){
        sum += nums[i];
      }
       ans = Math.max(sum , ans);
       i = k-1;
      for( j=nums.length-1;j>=(nums.length-k);j--){
         sum += nums[j];
         sum -= nums[i];
         i--;
         ans = Math.max(sum , ans);
      }

      return ans;
    }
}