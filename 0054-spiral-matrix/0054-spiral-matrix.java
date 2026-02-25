class Solution {
    public List<Integer> spiralOrder(int[][] mat) {
        List<Integer>ans = new ArrayList<>();
        int top =0, bottom = mat.length-1,l = 0, r = mat[0].length-1;
        while(top <= bottom && l<= r){
           for(int i=l;i<=r;i++){
             ans.add(mat[top][i]);
           }
           top++;
           for(int i=top;i<=bottom;i++){
              ans.add(mat[i][r]);
           }
           r--;
           if(top<=bottom){
           for(int i=r;i>=l;i--){
              ans.add(mat[bottom][i]);
           }
           bottom--;
           }
           
           if(l<=r){
           for(int i=bottom;i>=top;i--){
             ans.add(mat[i][l]);
           }
           l++;
           }
           
        }
        return ans;
    }
}