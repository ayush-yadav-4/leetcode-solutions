class Solution {

    class Disjoint{
        List<Integer> Rank = new ArrayList<>();
        List<Integer> parent = new ArrayList<>();

        Disjoint(int n){
         for(int i=0;i<(n*n);i++){
           parent.add(i);
           Rank.add(1);
         }
        }

        int getParent(int u){
            if(parent.get(u) == u) return u;
            int p = getParent(parent.get(u));
            parent.set(u, p);
            return p;
        }

        void UnionByRank(int u, int v){
          int paren_u = getParent(u);
          int paren_v = getParent(v);

          if(paren_u == paren_v){
                 return;
          }
          if(Rank.get(paren_u) < Rank.get(paren_v)){
            parent.set(paren_u, paren_v);
             Rank.set(paren_v, Rank.get(paren_v) + Rank.get(paren_u));
          }
          else if(Rank.get(paren_u) > Rank.get(paren_v)){
           parent.set(paren_v, paren_u);
            Rank.set(paren_u, Rank.get(paren_v) + Rank.get(paren_u));
          }
          else{
             parent.set(paren_u, paren_v);
             Rank.set(paren_v, Rank.get(paren_v) + Rank.get(paren_u));
          }
          return;
      
        }

    }
    public int largestIsland(int[][] grid) {
        int n = grid.length;
        Disjoint ds = new Disjoint(grid.length);
       int[] drow = {0,0,-1,+1};
       int[] dcol = {-1,+1,0,0};
        for(int row =0;row<grid.length;row++){
          for(int col =0;col<grid[0].length;col++){
              if(grid[row][col] == 1){
                for(int i=0;i<4;i++){
                    int r = row + drow[i];
                    int c = col + dcol[i];

                    if(r >= 0 && r < grid.length && c>=0 && c< grid[0].length && grid[r][c] == 1){
                        int node = row * n + col;
                        int adjnode = r * n + c;
                        ds.UnionByRank(node, adjnode);
                    }
                }
              }
          }
        }
        int ans = 0;
            for(int row =0;row<grid.length;row++){
          for(int col =0;col<grid[0].length;col++){
            
              if(grid[row][col] == 0){
                 int sum =0;
            Set<Integer> st = new HashSet<>();
                for(int i=0;i<4;i++){
                    int r = row + drow[i];
                    int c = col + dcol[i];

                    if(r >= 0 && r < grid.length && c>=0 && c< grid[0].length && grid[r][c] == 1){
                        
                        int adjnode = r * n + c;
                     
                       int paren_adjnode= ds.getParent(adjnode); 
                       st.add(paren_adjnode);                
                       }
                }

                for(int elem : st){
                  sum += ds.Rank.get(elem);
                }
                ans = Math.max(ans, sum+1);
              }
              
          }
        }

        for(int i = 0; i < n*n; i++){
    if(ds.getParent(i) == i){
        ans = Math.max(ans, ds.Rank.get(i));
    }
}

       return ans;
    }
}