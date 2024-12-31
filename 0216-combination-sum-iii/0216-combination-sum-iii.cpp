class Solution {
public:
void helper( vector<vector<int>>&ans,vector<int>temp,int k ,int n,int idx){
   
   if(n ==0 && k ==0){
    ans.push_back(temp);
    return;
   }
   if(n<0 || k<0 || idx >9){
    return;
   }

   temp.push_back(idx);
   helper(ans,temp,k-1,n-idx,idx+1);
   temp.pop_back();

    helper(ans,temp,k,n,idx+1);
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;  vector<int>temp;
        helper(ans,temp,k,n,1);
        return ans;
    }
};