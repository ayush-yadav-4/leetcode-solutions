class Solution {
public:

   void helper(vector<int>& arr,vector<vector<int>>& ans,vector<int>& temp, int target,int idx ){
    if(idx == arr.size() ||  target < 0) return;
    if(target == 0){
            ans.push_back(temp);
            return;
        }
  

    temp.push_back(arr[idx]);
    helper(arr,ans,temp, target-arr[idx], idx);
    temp.pop_back();
    helper(arr,ans,temp, target, idx+1);
   }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>>ans; vector<int>temp;
        helper(arr,ans,temp,target,0);
        return ans;
    }
};