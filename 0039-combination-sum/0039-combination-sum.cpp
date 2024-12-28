class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>temp;
        helper(candidates,target,ans,temp,0);
        return ans;
    }
    void helper(vector<int>& candidates, int target ,vector<vector<int>>& ans, vector<int>& temp,int i)  {
        if(target == 0){
          ans.push_back(temp);
          return;
        }
        if(target< 0 || i == candidates.size()){
          return;
        }
   
            temp.push_back(candidates[i]);
           helper(candidates,target-candidates[i],ans,temp,i);
            temp.pop_back();

          helper(candidates,target,ans,temp,i+1);
        
    }
};