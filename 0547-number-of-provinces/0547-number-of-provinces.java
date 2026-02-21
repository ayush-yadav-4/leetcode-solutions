class Solution {
    class Disjoint{

        ArrayList<Integer> parent = new ArrayList<>();
        ArrayList<Integer>Rank = new ArrayList<>();

        Disjoint(int n){
            
         for(int i=0;i<n;i++){
              parent.add(i);
              Rank.add(0);
         }
        } 

         int findParent(int u){
             if(u == parent.get(u)) return u;

            int ultimateParent = findParent(parent.get(u));
            parent.set(u, ultimateParent);
            return ultimateParent;
         }

         void unionByRank(int u, int v){
           int paren_u = findParent(u);
           int paren_v = findParent(v);
           if(paren_u == paren_v) return;

           if(Rank.get(paren_u) < Rank.get(paren_v)){
             parent.set(paren_u, paren_v);
           }
           else if(Rank.get(paren_v) < Rank.get(paren_u)){
             parent.set(paren_v, paren_u);
           }
           else{
              parent.set(paren_u,paren_v);
             Rank.set(paren_v,Rank.get(paren_v)+1);
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
        boolean[] vis = new boolean[mat.length];
        Arrays.fill(vis,false);
        for(int i=0;i<mat.length;i++){
           for(int j=0;j<mat[i].length;j++){
            //   if(vis[i] == false && mat[i][j] == 1){
            //     cnt++;
                
            //     DFS(mat,i,vis);
            //   }

            if(mat[i][j] == 1){
             ds.unionByRank(i,j);

            }
           }
        }

        for(int i=0;i<mat.length;i++){
          if(ds.findParent(i) == i) cnt++;
        }
        return cnt;
    }
}