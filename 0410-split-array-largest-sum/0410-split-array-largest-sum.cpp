class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int start =0,end=0,mid=0,count=0,ans=0,sum=0;
        for(int i = 0; i < nums.size(); i++){
            start = max(start , nums[i]);
            end += nums[i];
        }

        while(start<= end){
            mid = start + (end-start)/2;
            count=1;sum=0;
            for(int i =0 ; i < nums.size(); i++){
               sum += nums[i];
               if(sum > mid){
                count++;
                sum = nums[i];
               }
            }

            if(count<=k){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
};