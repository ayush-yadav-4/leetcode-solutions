class Solution {
    public int[] findDegrees(int[][] matrix) {
        int[] ans = new int[matrix.length];
        Arrays.fill(ans,0);

        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix[0].length;j++){
               if(matrix[i][j] == 1){
                 ans[j]++;
               }
            }
        }

        return ans;
    }
}