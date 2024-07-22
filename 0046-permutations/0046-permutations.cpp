class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>visited(nums.size(),0);
        vector<vector<int>>ans;
        vector<int>temp;
        helper(nums,visited,temp,ans,0);
        return ans;
    }

    void helper(vector<int>& nums , vector<int> &visited,vector<int>&temp ,vector<vector<int>>&ans,int idx){

        if(visited.size() == temp.size()){
             ans.push_back(temp);
             return;
        }
        
        for(int i=0 ; i<visited.size(); i++){
             if(visited[i] == 0){
                visited[i] = 1;
                temp.push_back(nums[i]);
                helper(nums, visited, temp,ans,idx+1);
                visited[i] = 0;
                temp.pop_back();
             }
        }

    }
};