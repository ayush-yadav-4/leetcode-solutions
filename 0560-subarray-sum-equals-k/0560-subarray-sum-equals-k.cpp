class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       int sum =0,pos=0;
       for(int i =0; i< nums.size()-1;i++){
        sum = nums[i];
        if(sum == k){
          pos++;
        }
        for(int j =i+1 ;j< nums.size();j++){
            sum += nums[j];
            if(sum == k){
                pos++;
            }
        }
       }
       if(nums[nums.size()-1] == k){ pos++;}
       return pos;
    }
};