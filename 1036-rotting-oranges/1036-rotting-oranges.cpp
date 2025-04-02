class Solution {
public:
 
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0,start = -1,frsh = 0,cntfrsh = 0,time = 0;
       queue<pair<pair<int,int>,int>>q;
        int n = grid.size(); int m = grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
         for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
             if(grid[i][j] == 2){
                visited[i][j] = 2;
                q.push(make_pair(make_pair(i,j),0));
                
             }
             else visited[i][j] = 0; 
             if(grid[i][j] == 1)frsh++;
            }  
        }

        int drow[] = {-1,+1,0,0}; int dcol[] = {0,0,-1,+1};
        while(!q.empty()){
          int r = q.front().first.first;
          int c = q.front().first.second;
          int t = q.front().second;
          time = t;
          q.pop();
          for(int i=0;i<4;i++){
           int nrow = r + drow[i];
           int ncol = c + dcol[i];

           if(nrow<n && nrow>=0 && ncol < m && ncol >= 0 && grid[nrow][ncol] == 1 && visited[nrow][ncol] != 2){
                visited[nrow][ncol] = 2;
                q.push({{nrow,ncol},t+1});
                cntfrsh++;
           }
          }


        }

        if(frsh != cntfrsh) return -1;
       
        return time;
    }
};