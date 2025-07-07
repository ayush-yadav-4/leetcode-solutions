
class Disjoint{

public:
vector<int> size,par;
  Disjoint(int v){
    size.resize(v,1);
    par.resize(v);
    for(int i=0;i<v;i++){
         par[i] = i;
    }
  }

  int findparent(int u){
    if(par[u] == u) return u;

    return par[u] = findparent(par[u]);
  }

  void unionbysize(int u,int v){
      int par_u = findparent(u);
       int par_v = findparent(v);

       if(par_u == par_v) return;
       else if(size[par_u] > size[par_v]){
           par[par_v] = par_u;
           size[par_u] += size[par_v];
       }
       else{
         par[par_u] = par_v;
           size[par_v] += size[par_u];
       }

  }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
       Disjoint d(isConnected.size());
        for(int i = 0;i<isConnected.size();i++){
            for(int j = 0;j<isConnected[0].size();j++){
              if(isConnected[i][j] == 1){
                d.unionbysize(i,j);
              }
            }
        }
        int cnt = 0;
        for(int i=0;i<isConnected.size();i++){ 
           if(d.findparent(i) == i)cnt++;
        }
        return cnt;
    }
};