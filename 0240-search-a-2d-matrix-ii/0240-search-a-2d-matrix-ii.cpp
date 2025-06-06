class Solution {
public:
 
    bool searchMatrix(vector<vector<int>>& mat, int target) {
         int row =0, col = mat[0].size()-1,mid=0,n=mat.size()-1;
         while(row <= mat.size()-1 && col >=0){
             
             if(mat[row][col] == target) return true;
             else if(mat[row][col] < target) row++;
             else col--;         
         }
         return false;
    }
};