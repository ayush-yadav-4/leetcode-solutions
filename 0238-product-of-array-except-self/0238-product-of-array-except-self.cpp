class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
         vector<int>ans(n,1);
         vector<int>suffix(n,1);
         vector<int>prefix(n,1);
         int sum =1,flag =0,a=0;
         prefix[0]=1;
         for(int i=1;i< nums.size();i++ ){
            prefix[i] = prefix[i-1]*nums[i-1];
         }
            suffix[nums.size()-1]=1;
         for(int i=nums.size()-2;i>=0;i-- ){
            suffix[i] = suffix[i+1]*nums[i+1];
         }
         for(int i =0; i<nums.size();i++){
            ans[i] = prefix[i]*suffix[i];
         }
    
        return ans;
    }
};