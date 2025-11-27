class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int st = 0,end = 0, sum = 0;
        while(end<nums.size()){
          sum += nums[end];
          
          while(st<end && sum>target){
            if(sum>= target){ans = min(ans,end-st+1);}
             sum -= nums[st];
             st++;
             
          }

          if(sum>= target){ans = min(ans,end-st+1);}
          end++;
        }
        if(ans == INT_MAX) return 0;
        return ans;
    }
};