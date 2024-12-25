class Solution {
public:
    vector<int> row(int row){
        vector<int>rowidx; long long ans = 1;
        rowidx.push_back(1);
      for(int i=1  ; i < row;i++){
           ans = ans* (row-i);
           ans = ans/(i);
           rowidx.push_back(ans);
       } 
       return rowidx;
    }
    vector<vector<int>> generate(int numRows) {
       vector<vector<int>>ans;

       for(int i =1;i<=numRows;i++ ){
           ans.push_back(row(i));
       }
       return ans;
    }
};