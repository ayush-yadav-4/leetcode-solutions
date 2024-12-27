class Solution {
public:
    void subset(vector<vector<int>>&ans,vector<int>&temp,vector<int>& nums,int i){
        
        if(i == nums.size()){
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(nums[i]);
        //Include
        subset(ans,temp,nums,i+1);

        //Backtracking part
        temp.pop_back();
        //Exclude
        subset(ans,temp,nums,i+1);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
         vector<vector<int>>ans;vector<int>temp;int i = 0;
         subset(ans,temp,nums,i);
         return ans;
    }
};