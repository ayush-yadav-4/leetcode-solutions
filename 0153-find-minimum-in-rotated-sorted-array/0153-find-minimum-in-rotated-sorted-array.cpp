class Solution {
public:
    int findMin(vector<int>& nums) {
        int st =0,end = nums.size()-1,mid=0,ans=INT_MAX;
        while(st<=end){
            mid = st + (end-st)/2;
            if(nums[st] <= nums[mid]){
                ans = min(ans,nums[st]);
                st = mid+1;
            }
            else{
                ans = min(ans,nums[mid]);
                end = mid-1;
            }
        }
        return ans;
    }
};