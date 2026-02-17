class Solution {
    class Pair{
        int row; int col; int wt;
        Pair(int row, int col, int wt){
     this.row = row;
     this.col= col;
     this.wt = wt;
        }
    }
    public int shortestPathBinaryMatrix(int[][] grid) {
        if(grid[0][0] == 1) return -1;
        if(grid.length == 0 || grid[0].length == 0) return -1;

        int finalrow = grid.length-1;
        int finalcol = grid[0].length-1;
         Queue<Pair> q = new LinkedList<>();
         q.add(new Pair(0,0,0));
         int rows[] ={-1,-1,-1,0,0,1,1,1};
         int cols[] = {-1,0,+1,-1,1,-1,0,+1};
         while(q.size() > 0){
           Pair p = q.poll();
           int row = p.row;
           int col = p.col;
           int wt = p.wt;
           if(p.row == finalrow && p.col == finalcol){
            return p.wt + 1;
           }

           for(int i=0;i<8;i++){
             int r = row + rows[i];
             int c = col + cols[i];
            if(r >=0 && r< grid.length && c >=0 && c < grid[0].length && grid[r][c] == 0){
                grid[r][c] = 1;
              q.add(new Pair(r,c,wt+1));
            }
            
           }
         }

         return -1;
    }
}