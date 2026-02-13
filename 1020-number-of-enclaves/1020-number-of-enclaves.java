class Solution {
          class Pair{
        int row; int col;
        Pair(int row, int col ){
            this.row = row;
            this.col = col;
            
        }
    }
    public int numEnclaves(int[][] grid) {
        
        Queue<Pair> q = new LinkedList<>();
        int[][] vis = new int[grid.length][grid[0].length];;
        for(int i=0;i<grid.length;i++){
          if(grid[i][0] == 1){
              q.add(new Pair(i,0));
              grid[i][0] = 0;
          }
          if(grid[i][grid[0].length-1] == 1){
     q.add(new Pair(i,grid[0].length-1));
      grid[i][grid[0].length-1] = 0;
          }
        }
        for(int i=0;i<grid[0].length;i++){
           if(grid[0][i] == 1){
              q.add(new Pair(0,i));
               grid[0][i] = 0;
          }
          if(grid[grid.length-1][i] == 1){
            q.add(new Pair(grid.length-1,i));
             grid[grid.length-1][i] = 0;
          }
        }
        

         int rows[] = {0,0,-1,+1};
           int cols[]= {-1,+1,0,0};
           while(q.size() > 0){
             Pair p = q.poll();
            
             for(int i=0;i<4;i++){
               int r = p.row + rows[i];
               int c = p.col + cols[i];

               if(r>=0 && r < grid.length && c>=0 && c < grid[0].length && grid[r][c] == 1 ){
                  q.add(new Pair(r,c));
                  grid[r][c] = 0;
                 
                 
               }
             }

          }
            int cnt = 0;
          for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                if(grid[i][j] == 1){
                   cnt++;
               }
            }
          }
          return cnt;
    }
}