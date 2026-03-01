class Solution {


class Disjoint {

    ArrayList<Integer> parent = new ArrayList<>();
    ArrayList<Integer> rank = new ArrayList<>();

    // Constructor
    Disjoint(int n) {
        for (int i = 0; i <= n; i++) {
            parent.add(i);   // parent of itself
            rank.add(0);     // initial rank = 0
        }
    }

    // Find Parent (Path Compression)
    int Parent(int u) {
        if (parent.get(u) == u)
            return u;

        int ultParent = Parent(parent.get(u));
        parent.set(u, ultParent);   // path compression
        return parent.get(u);
    }

    // Union By Rank
    void unionByRank(int u, int v) {

        int paren_u = Parent(u);
        int paren_v = Parent(v);

        if (paren_u == paren_v) return;

        if (rank.get(paren_u) < rank.get(paren_v)) {
            parent.set(paren_u, paren_v);
        }
        else if (rank.get(paren_u) > rank.get(paren_v)) {
            parent.set(paren_v, paren_u);
        }
        else {
            parent.set(paren_v, paren_u);
            rank.set(paren_u, rank.get(paren_u) + 1);
        }
    }
}    
    
    void DFS(int[][] mat, int i,boolean[] vis){
         vis[i] = true;

         for(int idx =0;idx<mat[i].length;idx++){
           if(mat[i][idx] == 1 && vis[idx] == false){
             DFS(mat,idx,vis);
           }
         }
    }
    public int findCircleNum(int[][] mat) {
        int cnt = 0;
        Disjoint ds = new Disjoint(mat.length);
        for(int i=0;i<mat.length;i++){
            for(int j =0;j<mat[0].length;j++){
              if(mat[i][j] == 1){
                ds.unionByRank(i,j);
              }
            }
        }

        for(int i=0;i<mat.length;i++){
          if(ds.parent.get(i) == i){
            cnt++;
          }
        }
        return cnt;
       
    }
}