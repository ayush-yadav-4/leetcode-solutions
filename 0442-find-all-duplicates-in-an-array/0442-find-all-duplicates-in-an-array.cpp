class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>dupl;
        for(int i=0;i<nums.size();i++){
          if(nums[abs(nums[i])-1] < 0){
           dupl.push_back(abs(nums[i]));
          }
            nums[abs(nums[i])-1] = nums[abs(nums[i])-1]*(-1);

        }
        return dupl;
    }
};