class Solution {
    // int check(int r, int c , int[][] mat){
    //   int[] rows = {0,0,-1,+1};
    //   int[] cols = {-1,+1,0,0};
    //   int mini = 10000000;
    //   for(int i=0;i<4;i++){
    //      int row = r + rows[i];
    //      int col = c + cols[i];

    //      if(row>=0 && row< mat.length && col >=0 && col < mat[0].length ){
    //        mini = Math.min(mini, mat[row][col]);
    //      } 
         
    //   }
    //   return mini;
    // }

    class Pair{
        int row; int col; int val;
        Pair(int row, int col , int val){
            this.row = row;
            this.col = col;
            this.val = val;
        }
    }
    public int[][] updateMatrix(int[][] mat) {
          Queue<Pair> q = new LinkedList<>();
          int[][] vis = new int[mat.length][mat[0].length];;
          int[][] ans = new int[mat.length][mat[0].length];

          for(int[] a : vis){
           Arrays.fill(a,0);
          }
          int cnt = 0;
          for(int i=0;i<mat.length;i++){
            for(int j=0;j<mat[i].length;j++){
                if(mat[i][j] == 1)cnt++;
              if(mat[i][j] == 0){
                 q.add(new Pair(i,j,0));
                 vis[i][j] = 1;
                 ans[i][j] = 0;
              }
            }
          }
          if(cnt == 0) return mat;
           int rows[] = {0,0,-1,+1};
           int cols[]= {-1,+1,0,0};
          while(q.size() > 0){
             Pair p = q.poll();
          
             for(int i=0;i<4;i++){
               int r = p.row + rows[i];
               int c = p.col + cols[i];

               if(r>=0 && r < mat.length && c>=0 && c < mat[0].length && vis[r][c] == 0 && mat[r][c] == 1 ){
                  q.add(new Pair(r,c,p.val +1));
                  ans[r][c] = p.val +1;
                  vis[r][c] = 1;
               }
             }

          }

        //   for(int i=mat.length-1;i>=0;i--){
        //     for(int j=mat[i].length-1;j>=0;j--){
        //       if(mat[i][j] == 1){
        //         int elem = check(i,j,mat);
        //         mat[i][j] = elem + 1;
        //       }
        //     }
        //   }
          return ans;
    }
}