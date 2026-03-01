class Solution {

    class Disjoint{

        List<Integer> parent = new ArrayList<>();
        List<Integer> Rank = new ArrayList<>();

        Disjoint(int n){
           for(int i=0;i<n;i++){
             parent.add(i);
             Rank.add(0);
           }
        }

        int Parent(int u){
          if(parent.get(u) == u) return u;
          int ultParen =  Parent(parent.get(u));

          parent.set(u ,ultParen);
          return parent.get(u);
        }

        void unionByRank(int u, int v){
            int paren_u = parent.get(u);
            int paren_v = parent.get(v);

            if(paren_u == paren_v) return;
            if(Rank.get(paren_u) < Rank.get(paren_v)){
                parent.set(paren_u , paren_v);
            }
            else if(Rank.get(paren_u) > Rank.get(paren_v)){
               parent.set(paren_v , paren_u);
            }
            else{
                  parent.set(paren_v , paren_u);
                  Rank.set(paren_u,Rank.get(paren_u)+1 );
            }
        }

    }
    public int makeConnected(int n, int[][] connections) {
         int cnt = 0; int cable =0;
         Disjoint ds = new Disjoint(n);
         for(int i=0;i<connections.length;i++){
            int u = connections[i][0];
            int v = connections[i][1];
            if(ds.Parent(u) == ds.Parent(v)){
                cable++;
            }
             else ds.unionByRank(connections[i][0], connections[i][1]);
         }
        
         
         
            for(int i=0;i<n;i++){
            if(ds.parent.get(i) == i){
                cnt++;
            }
         }

         if(cable < (cnt-1)) return -1;
         return cnt-1;
    }
}