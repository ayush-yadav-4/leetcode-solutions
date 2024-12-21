class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1, last = -1, flag =0;
        vector<int>ans;
        for(int i =0 ; i < nums.size(); i++){
           if(nums[i] == target && flag ==0){
            first = i ; 
            last = i; flag =1;}
            if(nums[i] == target && i > last && flag == 1){
                last = i;
            }
           
        }
        ans.push_back(first); ans.push_back(last);
        return ans;
    }
};