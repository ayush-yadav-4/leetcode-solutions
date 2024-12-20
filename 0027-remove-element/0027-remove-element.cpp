class Solution {
public:

    int removeElement(vector<int>& nums, int val) {
      if(nums.size()<1){
        return 0;
      }
      int k=0,j=0;
      for(int i =0;i < nums.size(); i++){
        if(nums[i] != val){
            nums[j] = nums[i];
            j++;
        }
      }
      return j;
 

    }
};