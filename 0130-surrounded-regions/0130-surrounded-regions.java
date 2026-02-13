class Solution {
     class Pair{
        int row; int col;
        Pair(int row, int col ){
            this.row = row;
            this.col = col;
            
        }
    }
    public void solve(char[][] mat) {
         Queue<Pair> q = new LinkedList<>();
         
          int[][] ans = new int[mat.length][mat[0].length];
           int[][] vis = new int[mat.length][mat[0].length];;
         int n = mat.length-1;
         
          for(int[] a : vis){
           Arrays.fill(a,0);
          }
          for(int i=0;i<mat.length;i++){
           
               if(mat[i][0] == 'O'){
                q.add(new Pair(i,0));
               }
               if(mat[i][mat[0].length-1] == 'O'){
                q.add(new Pair(i,mat[0].length-1));
               }
            
          }
           for(int i=0;i<mat[0].length;i++){
           
               if(mat[0][i] == 'O'){
                q.add(new Pair(0,i));
               }
               if(mat[n][i] == 'O'){
                q.add(new Pair(n,i));
               }
            
          }
             int rows[] = {0,0,-1,+1};
           int cols[]= {-1,+1,0,0};
           while(q.size() > 0){
             Pair p = q.poll();
             vis[p.row][p.col] = 1;
             for(int i=0;i<4;i++){
               int r = p.row + rows[i];
               int c = p.col + cols[i];

               if(r>=0 && r < mat.length && c>=0 && c < mat[0].length && mat[r][c] == 'O' && vis[r][c] == 0){
                  q.add(new Pair(r,c));
                  vis[r][c] = 1;
                 
               }
             }

          }

          for(int i=0;i<mat.length;i++){
            for(int j=0;j<mat[0].length;j++){
                if(mat[i][j] == 'O' && vis[i][j] == 0){
                mat[i][j] = 'X';
               }
            }
          }
         


           
    }
}