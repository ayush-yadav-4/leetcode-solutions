class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i=0,l=0,ans=0; long long int sum=1;
        while(i<=nums.size()-1){
            sum *= nums[i];
          while(sum>=k && l<=i){
            sum = sum / nums[l];
            l++;
          }
        
            ans += (i-l)+1;
          i++;
        }
        return ans;
    }
};