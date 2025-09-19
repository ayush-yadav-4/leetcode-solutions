class Solution {
public:


void helper(vector<int>& arr,int idx, int target,vector<vector<int>>&ans,vector<int>&temp){
    if(idx<0) return;
    if(target<0) return;
    if(target==0){
        ans.push_back(temp);
        return;
    }
    
   
   temp.push_back(arr[idx]);
    helper(arr,idx,target-arr[idx],ans,temp);
    temp.pop_back();
    helper(arr,idx-1,target,ans,temp);


}
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;vector<int> temp;
       helper(arr,arr.size()-1,target,ans,temp);
       return ans;
    }
};