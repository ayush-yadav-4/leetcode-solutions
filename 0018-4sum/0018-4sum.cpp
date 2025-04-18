class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
         vector<vector<int>>ans;
         int start=0,end=0; long long sum=0;
        for(int i=0;i<nums.size()-1;i++){
            if(i>0 && nums[i] == nums[i-1])continue;
            for(int j=i+1;j<nums.size();j++){
               if(j>i+1 && nums[j] == nums[j-1])continue;
               start = j+1; end = nums.size()-1;
               while(start<end){
                sum = (long long)nums[i] + (long long)nums[j] + 
                          (long long)nums[start] + (long long)nums[end]; 

                if(sum<target){
                    start++;
                }
                else if(sum>target)end--;
               
               else {
                ans.push_back({nums[i],nums[j],nums[start],nums[end]});
                start++;end--;
                while( start<end && nums[start] == nums[start-1])start++;
               }
            }
            }
        }
        return ans;
    }
};