class Solution {
public:
int minsum(vector<int>& nums){
    int best = 0, ans = 0;
  for(int i = 0;i<nums.size();i++){
    int v1 = nums[i];
    int v2 = nums[i] + best;
   best = min(v1,v2);
    ans = min(ans,best);

  }
  return ans;
  
}
int maxsum(vector<int>& nums){
    int best = 0, ans = 0;
  for(int i = 0;i<nums.size();i++){
    int v1 = nums[i];
    int v2 = nums[i] + best;

    best = max(v1,v2);
    ans = max(ans,best);
  }
  return ans;
}
    int maxAbsoluteSum(vector<int>& nums) {
        if(nums.size() == 1) return abs(nums[0]);
         int minans = minsum(nums);
         int maxans = maxsum(nums);
         int sum = 0;
         for(int i = 0;i<nums.size();i++){
           sum += nums[i];
         }
         return max(maxans,max(abs(minans),abs(sum)));
    }
};