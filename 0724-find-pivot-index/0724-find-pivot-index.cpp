class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      
        int n = nums.size();
        // vector<int>suffix(nums.size(),0);
        // vector<int>prefix(nums.size(),0);
        // prefix[0] = nums[0];
        // suffix[n-1] = nums[n-1];
        int sum = 0;
        int suffix = 0, prefix = 0;
         for(int arr : nums){
          sum += arr;
         }
        for(int i = 0;i<nums.size();i++){
          
          int suffix = sum - prefix - nums[i];
    if(prefix == suffix) return i;
    prefix += nums[i];
            
        }

        //  for(int i = n-2;i>=0;i--){
        //     suffix[i] = nums[i+1] + suffix[i+1];
            
        // }
        // for(int i = 0;i<nums.size();i++){
        //   if(prefix[i] == suffix[i]) return i;
        // }

        return -1;
    }
};