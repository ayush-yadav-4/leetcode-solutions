class Solution {
public:
    int pivotIndex(vector<int>& nums) {
       
        int n = nums.size();
        vector<int>suffix(nums.size(),0);
        vector<int>prefix(nums.size(),0);
        // prefix[0] = nums[0];
        // suffix[n-1] = nums[n-1];

        for(int i = 1;i<nums.size();i++){
            prefix[i] = nums[i-1] + prefix[i-1];
            
        }

         for(int i = n-2;i>=0;i--){
            suffix[i] = nums[i+1] + suffix[i+1];
            
        }
        for(int i = 0;i<nums.size();i++){
          if(prefix[i] == suffix[i]) return i;
        }

        return -1;
    }
};