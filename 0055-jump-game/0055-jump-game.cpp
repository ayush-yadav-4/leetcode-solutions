class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1)return true;
        int target=nums.size()-1,maxidx=0;
        for(int i=0;i<nums.size();i++){
            if(i>maxidx) return false;
             maxidx = max(maxidx,nums[i]+i);
             if(maxidx>=target)return true;
           
          
        }
        return true;
    }
};