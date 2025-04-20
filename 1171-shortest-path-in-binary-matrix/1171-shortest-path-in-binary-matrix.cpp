class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        vector<vector<int>>dist(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        queue<pair<int,pair<int,int>>>q;

        q.push({1,{0,0}});
        dist[0][0] = 1;
         int row[] = {0,0,-1,+1,-1,+1,-1,+1};
          int col[] = {-1,+1,0,0,-1,+1,+1,-1};
        while(!q.empty()){
          int wt = q.front().first;
          int r = q.front().second.first;
          int c = q.front().second.second;
          q.pop();

         
          
          for(int i=0;i<8;i++){
            int nrow = r + row[i];
            int ncol = c + col[i];
            if(nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid[0].size()){
             if(grid[nrow][ncol] == 0 && dist[nrow][ncol] > dist[r][c] + 1){
                dist[nrow][ncol] = dist[r][c] + 1;
                q.push({dist[nrow][ncol],{nrow,ncol}});
             }
            }
          }
        }
        if(dist[dist.size()-1][dist[0].size()-1] == INT_MAX) return -1;
        return dist[dist.size()-1][dist[0].size()-1];
    }
};