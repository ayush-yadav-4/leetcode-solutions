class Solution {
public:

void BFS(vector<vector<int>>& grid,vector<vector<int>>& vis,int row,int col){
 
   queue<pair<int,int>>q;
   q.push({row,col});
   vis[row][col] = 1;

 int rows[] = {0,0,-1,+1};
     int cols[] = {-1,+1,0,0};
   while(!q.empty()){
     int r = q.front().first;
     int c = q.front().second;
     q.pop();
     
     
    
     for(int i=0;i<4;i++){
       int ro = r + rows[i];
       int co = c + cols[i];
      if(ro>=0 && co<grid[0].size()-1 && co>=0 && ro<grid.size()-1 && vis[ro][co] == 0 && grid[ro][co] == 1){
         vis[ro][co]= 1;
        q.push({ro,co});
        
        
      } 

     }
   }
}
    int numEnclaves(vector<vector<int>>& grid) {
        

        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1 && vis[i][0] == 0)
                BFS(grid, vis, i, 0);
            if (grid[i][n - 1] == 1 && vis[i][n - 1] == 0)
                BFS(grid, vis, i, n - 1);
        }

        
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1 && vis[0][j] == 0)
                BFS(grid, vis, 0, j);
            if (grid[m - 1][j] == 1 && vis[m - 1][j] == 0)
                BFS(grid, vis, m - 1, j); 
        }

        int cnt = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
               if(grid[i][j] == 1 && vis[i][j] == 0){
                  cnt++;
               }
            }
        }
        return cnt;   
    }
};