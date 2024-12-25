class Solution {
public:

    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1){
       return nums[nums.size()-1];
}
        int ans =0;
        
        for(int i =1;i<nums.size();i++){
             if(i == nums.size()-1 && ans ==0){
                if(nums[0] != nums[1]){
                    return nums[0];
                }else if (nums[nums.size()-1] != nums[nums.size()-2]){
                  return nums[nums.size()-1];
                }
                
           }
           else if(nums[i] != nums[i-1] && nums[i] != nums[i+1]){
               ans = nums[i];
           }
          
        }
        return ans;
       
    }
};