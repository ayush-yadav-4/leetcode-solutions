class Solution {

    void DFS(int[][] mat, int i,boolean[] vis){
         vis[i] = true;

         for(int idx =0;idx<mat[i].length;idx++){
           if(mat[i][idx] == 1 && vis[idx] == false){
             DFS(mat,idx,vis);
           }
         }
    }
    public int findCircleNum(int[][] mat) {
        int cnt = 0;

        boolean[] vis = new boolean[mat.length];
        Arrays.fill(vis,false);
        for(int i=0;i<mat.length;i++){
           for(int j=0;j<mat[i].length;j++){
              if(vis[i] == false && mat[i][j] == 1){
                cnt++;
                
                DFS(mat,i,vis);
              }
           }
        }
        return cnt;
    }
}