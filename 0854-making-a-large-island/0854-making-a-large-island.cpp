class Disjoint {
public:
    vector<int> size, parent;
    Disjoint(int v) {
        size.resize(v, 1);
        parent.resize(v);
        for (int i = 0; i < v; i++) {
            parent[i] = i;
        }
    }

    int findparent(int u) {
        if (parent[u] == u) return u;
        return parent[u] = findparent(parent[u]);
    }

    void unionbysize(int u, int v) {
        int par_u = findparent(u);
        int par_v = findparent(v);

        if (par_u == par_v) return;
        if (size[par_u] > size[par_v]) {
            parent[par_v] = par_u;
            size[par_u] += size[par_v];
        } else {
            parent[par_u] = par_v;
            size[par_v] += size[par_u];
        }
    }
    
    int findparentsize(int u){
         int par = findparent(u);
         return size[par];
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        Disjoint d(n*m);
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        int ans = 0;
        int rows[] = {0,0,-1,+1};
        int cols[] = {-1,+1,0,0};
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
              if(grid[i][j] == 1 && vis[i][j] == 0){
                
              
                for(int k=0;k<4;k++){
                  int row = i+rows[k];
                  int col = j + cols[k];
                  if(row>=0 && row<grid.size() && col>=0 && col<grid[0].size() && grid[row][col] == 1){
                     int node = i*m +j;
                     int adjnode = row*m + col;
                      if(d.findparent(node) != d.findparent(adjnode)){
                        
                        d.unionbysize(node,adjnode);
                      }
                  }
                }
              }
            }
        }
        
       int size = 0,parent = -1,cnt = 0;
            for(int i=0;i<grid.size();i++){
                for(int j=0;j<grid[0].size();j++){
                    if(grid[i][j] == 0){
                        cnt++;
                     size = 1;
                     parent = -1;
                     set<int>comp;
                for(int k=0;k<4;k++){
                  int row = i+rows[k];
                  int col = j + cols[k];
                  if(row>=0 && row<grid.size() && col>=0 && col<grid.size() && grid[row][col] == 1){
                     int node = i*m +j;
                     int adjnode = row *m + col;
                     int par = d.findparent(adjnode);
                      if(comp.find(par) == comp.end()){
                         comp.insert(par);
                         size+= d.findparentsize(par);
                      }
                  }
                }
                ans = max(ans,size);
                    }
                }
            }
        
        if(cnt == 0) return n*m;
        return ans;
    }
};