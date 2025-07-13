class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxidx=0;
        for(int i=0;i<nums.size();i++){
            if(maxidx < i){
               return false;
            }
            maxidx = max(maxidx,nums[i] + i);
        }
        return true;
    }
};