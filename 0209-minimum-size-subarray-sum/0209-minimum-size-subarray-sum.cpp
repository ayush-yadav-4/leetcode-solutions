class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0,r=0,sum=0,ans=INT_MAX;
        while(r<nums.size()){
           sum += nums[r];
          
           while(sum > target){
            ans = min(ans,(r-l)+1);
             sum -= nums[l]; l++;
           }
            if(sum >= target)
           ans = min(ans,(r-l)+1);
        
           r++;
        }
        if(ans == INT_MAX) return 0;
        return ans;
    }
};