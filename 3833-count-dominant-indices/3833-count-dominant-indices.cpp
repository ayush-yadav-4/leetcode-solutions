class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        if(nums.size() == 1) return 0;
         int n = nums.size();
         int cnt =0,sum =0,avg =0;
        for(int i=0;i<=nums.size()-2;i++){
           if(i == nums.size()-2){
             if(nums[i] > nums[i+1]){ cnt++;}
             return cnt;
           }
           sum = 0;avg = 0;
           for(int j=i+1;j<nums.size();j++){
              sum += nums[j];
           }
           avg = (sum / (n - i-1));
           if(avg < nums[i])cnt++;
        }
        return cnt;
    }
};