class Solution {
public:
void helper(vector<vector<int>>&ans,vector<int>& nums,int idx){
  if(idx == nums.size()){
    ans.push_back(nums);
   return;
  }
 vector<int>visited(21,0);
  for(int i=idx;i<nums.size();i++){
 if(visited[nums[i]+10] == 0){
    
    swap(nums[i],nums[idx]);
    helper(ans,nums,idx+1);
    swap(nums[i],nums[idx]);
    visited[nums[i]+10] =1;
 }
  }
  
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         vector<vector<int>> ans;
         
         helper(ans,nums,0);
         return ans;
    }
};