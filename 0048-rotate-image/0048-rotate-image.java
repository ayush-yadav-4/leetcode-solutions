class Solution {


    public void rotate(int[][] mat) {
        
        for(int i=0;i<mat.length;i++){
          for(int j =i+1;j<mat.length;j++){
              int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
          }
        }
      
   
         for(int i=0;i<mat.length;i++){
             int left = 0, right = mat[0].length - 1;
           while(left < right){
                int temp = mat[i][left];
                mat[i][left] = mat[i][right];
                mat[i][right] = temp;
                left++;
                right--;
            }

         }
           

        return;
    }
}