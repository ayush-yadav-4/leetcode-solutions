class Solution {

    // void DFS(){
    //     cnt++;
    //     int rows[] = {};
    //     int cols[] = {};
    //     for(int idx=0;idx<4;idx++){
    //      int r = i + rows[idx];
    //      int c = j + cols[idx];
    //      if(r >=0 &7 r < grid.lenght && c > =0 && c < grid[0].length && grid[r][c] == 1){
    //         grid[r][c] = 2;
    //         DFS(r,c,grid,cnt);
    //      }
    //     }
    // }

    class Pair{
        int row; int col; int time;

        Pair(int row, int col, int time){
           this.row = row;
           this.col = col;
           this.time = time;
        }
    }
    public int orangesRotting(int[][] grid) {
        Queue<Pair>q = new LinkedList<>();
        int cnt = 0;
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[i].length;j++){
               if(grid[i][j] == 2){
                q.add(new Pair(i,j,0));
               }
               if(grid[i][j] == 1){
                cnt++;
               }
            }
        }

        if(cnt == 0) return 0;
        int ans = 0;
        int[] rows = {0,0,-1,+1};
        int[] cols = {-1,+1,0,0};
        while(q.size() > 0){
          Pair p = q.poll();
          int r = p.row;
          int c = p.col;
          int time = p.time;
          ans = Math.max(ans,time);
    
          for(int idx =0;idx<4;idx++){
             int row = r + rows[idx];
             int col = c + cols[idx];
             if(row>=0 && row < grid.length && col>= 0 && col < grid[0].length && grid[row][col] == 1 ){
               grid[row][col] = 2;
               q.add(new Pair(row,col, time+1));
             }
          }

        }
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[i].length;j++){
               if(grid[i][j] == 1){
                return -1;
               }
             
            }
        }

        return ans;
    }
}