class Solution {
public:
   int helper(vector<int>&arr){
  int ans =0,idx=0; int n= arr.size();
  stack<int>st;
  for(int i=0 ; i< arr.size();i++){
     while(!st.empty() && arr[st.top()]>arr[i]){
         int idx = st.top();
         st.pop();
         if(!st.empty())
         ans = max(ans,arr[idx] * (i-st.top()-1));
         else ans = max(ans,arr[idx]*i);
     }

     st.push(i);
  }

  while(!st.empty()){
      int idx = st.top();
      st.pop();
      if(!st.empty()){
      ans = max(ans,arr[idx]*(n-st.top()-1));}
      else { ans = max(ans,(arr[idx]*n));}
  }
  return ans;
}
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int>arr(matrix[0].size(),0); int maxi_wid = 0;
        int row = matrix.size(); int col = matrix[0].size();
        for(int j=0; j<row; j++){
        for(int i=0; i<col; i++){
            if(matrix[j][i] == '0'){
                arr[i] = 0;
            }else{
                arr[i] = arr[i]+1;
            }
        }
        maxi_wid = max(maxi_wid,helper(arr));
        }
        return maxi_wid;
    }
};