class Solution {
public:
    int BS(vector<int>& nums){
        int start =0,end = nums.size()-1,mid =0,ans = INT_MAX;
   while(start <=end){
    mid = start +(end-start)/2;
        if(nums[start] <= nums[mid]){
           ans = min(ans,nums[start]);
           start = mid+1;
        }
        else {
           ans = min(ans,nums[mid]);
           end = mid-1;
        }
    
    }
    return ans;
    }
    int findMin(vector<int>& nums) {
        return BS(nums);
    }
};