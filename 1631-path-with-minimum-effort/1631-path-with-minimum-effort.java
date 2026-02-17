class Solution {
    class Pair{
        int row; int col ; int wt;
        Pair( int row, int col ,int wt){
          this.row = row;
          this.col = col;
          this.wt = wt;
        }
    }
    public int minimumEffortPath(int[][] heights) {
        int[][] grid = new int[heights.length][heights[0].length];
        for(int[] a : grid){
            Arrays.fill(a,1000000);
        }
        int[] rows = {0,0,-1,+1};
        int[] cols = {-1,+1,0,0};
        PriorityQueue<Pair> pq = new PriorityQueue<>((a,b)->{
            return a.wt - b.wt;
        });
        int n = grid.length-1;
        int m = grid[0].length-1;
        int ans = 0;
        pq.add(new Pair(0,0,0));
        while(pq.size() > 0){
          Pair p = pq.poll();
         int row = p.row;
         int col = p.col;
         int wt = p.wt;
         ans = Math.max(ans,wt);
         if(row == n && col == m) return ans;
          for(int i=0;i<4;i++){
             int r = row + rows[i];
             int c = col + cols[i];
             
             if(r>=0 && r < grid.length && c >=0 && c < grid[0].length){
              if(grid[r][c] > Math.abs(heights[r][c] - heights[row][col])){
                grid[r][c] = Math.abs(heights[r][c] - heights[row][col]);
                pq.add(new Pair(r,c,grid[r][c]));
              }
             }
          }
        }

       if(grid[n][m] == 1000000) return 0;
       return ans;
    }
}