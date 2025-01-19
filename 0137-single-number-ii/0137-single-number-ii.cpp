class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int ans = 0;
        sort(nums.begin(),nums.end());
        
       for(int i=1; i< nums.size();i++){
          if(i == nums.size()-1 && nums[i] != nums[i-1] && ans ==0){ ans = nums[i]; break;}
          if(nums[i] != nums[i-1] && nums[i] != nums[i+1]){  ans = nums[i]; break;}
       }
       if(ans == 0) ans = nums[0];
       return ans;
        
    }
};