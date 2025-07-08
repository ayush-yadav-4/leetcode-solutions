class Disjoint{
    public:
    vector<int>size,parent;
    Disjoint(int v){
      size.resize(v,1);
      parent.resize(v);
      for(int i=0;i<v;i++){
        parent[i] = i;
      }
    }

    int findparent(int u){
       if(parent[u] == u) return u;
       return parent[u] = findparent(parent[u]);
    }

    void unionbysize(int u,int v){
       int par_u = findparent(u);
       int par_v = findparent(v);

       if(par_u == par_v) return;
       if(size[par_u] > size[par_v]){
         parent[par_v] = par_u;
         size[par_u] += size[par_v];
       }
       else{
        parent[par_u] = par_v;
         size[par_v] += size[par_u];
       }
     }

     int totalparen(int v){
        int ans = 0;
        for(int i=0;i<v;i++){
            if(parent[i] == i){
                ans++;
            }
        }
        return ans;
     }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        Disjoint d(n);
        int extra = 0;
        for(auto it : connections){
           int u = it[0];
           int v = it[1];
           if(d.findparent(u) == d.findparent(v)){
              extra++;
           }
           else{
            d.unionbysize(u,v);
           }
        }
        int par = d.totalparen(n);
        if(par-1 <= extra) return par-1;
        return -1;
    }
};