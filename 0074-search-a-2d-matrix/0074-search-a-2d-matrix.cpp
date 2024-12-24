class Solution {

 
public:
   bool searchelem(vector<vector<int>>& matrix, int target,int row){
           int start =0 , end = matrix[row].size()-1,mid =0;
         
         while(start<= end){
                mid = start + (end -start)/2;
                if(matrix[row][mid] == target ){
                    return true;
                }
                else if(matrix[row][mid] < target){
                    start = mid+1;
                }else{

                   end = mid -1;  
                }
                }
                return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start =0,end=matrix.size()-1,mid=0;
         bool ans = false;
         int n = matrix[0].size()-1;
        while(start<=end){
           mid = start + (end - start)/2;
            if(target == matrix[mid][0] || target == matrix[mid][n]){
               return true;
            }
           
            else if(target > matrix[mid][0] && target < matrix[mid][n] ){
                ans = searchelem( matrix, target , mid);
                return ans;
            }
             else if(target < matrix[mid][0] ){
                end = mid -1;
            }
            else{
                start = mid+1;
            }
        }

        return false;
    }
};