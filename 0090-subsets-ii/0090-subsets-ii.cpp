class Solution {
public:
set<vector<int>>s;
   void subset(vector<vector<int>>&ans,vector<int>&temp,vector<int>& nums,int i){
        
        if(i == nums.size()){
            sort(temp.begin(), temp.end());
            if(s.find(temp) == s.end()){
                 ans.push_back({temp});
                 s.insert(temp);
            }
           
            return;
        }
        
        temp.push_back(nums[i]);
        //Include
        subset(ans,temp,nums,i+1);

        //Backtracking part
        temp.pop_back();
         
        //Exclude
        subset(ans,temp,nums,i+1);
          int idx = i+1;
           while(idx<nums.size() && nums[idx] == nums[idx-1] ){
            idx++;
        }

     

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         vector<vector<int>>ans;vector<int>temp;int i = 0;
         sort(nums.begin(),nums.end());
         subset(ans,temp,nums,i);
         return ans;
    }
};