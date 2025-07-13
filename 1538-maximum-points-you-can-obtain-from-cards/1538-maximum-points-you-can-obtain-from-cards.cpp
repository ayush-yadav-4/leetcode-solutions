class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
         int ans = 0,sum=0,lsum = 0,rsum = 0,ridx = nums.size()-1;
           
            for(int i=0;i<k;i++){
           lsum  += nums[i];
          }
          sum = lsum;
          for(int i = k-1; i>=0;i--){
           
            lsum -= nums[i];
            rsum += nums[ridx--];
           
             sum = max(sum,lsum + rsum);
          }
         
        return sum;
    }
};