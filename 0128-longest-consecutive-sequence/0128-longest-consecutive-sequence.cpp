class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        stable_sort(nums.begin(),nums.end());
    int count =0,curr =INT_MIN,maxi =0;
        for(int i=0;i < nums.size();i++){
            if(nums[i]-1 == curr){
                curr = nums[i];
                count++;
            }
            else if(nums[i] == curr){
                continue;
            } 
            else{
                curr = nums[i];
                count =1;
            }
            maxi = max(count,maxi);

        }
        return maxi;
    }
};