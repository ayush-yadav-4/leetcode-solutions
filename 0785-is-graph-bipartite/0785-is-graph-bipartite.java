class Solution {
    class Pair{
        int elem;
        int color;

        Pair(int elem , int color){
         this.elem = elem;
         this.color = color;
        }
    }
    public boolean isBipartite(int[][] graph) {
         if(graph.length == 0 || graph.length == 1) return true;
         Queue<Pair> q = new LinkedList<>();
        
         int[] colours = new int[graph.length];
         int[] vis = new int[graph.length];

         Arrays.fill(colours,0);
         Arrays.fill(vis,0);
          
      for(int st = 0;st<graph.length;st++){
        if(vis[st] == 1) continue;

        q.add(new Pair(st,0));
        
            while(q.size() > 0){
           Pair p = q.poll();
           int elem = p.elem;
           int color = p.color;
            vis[elem] = 1;
            colours[elem] = color;
           for(int i=0;i<graph[elem].length;i++){
            int node = graph[elem][i];
             if(vis[node] == 1 && colours[node] == color){
                 return false;
             }
             else if(vis[node] == 0){
                vis[node] = 1;
                if(color == 1){
                    colours[node] = 2;
                }
                else colours[node] = 1;

                q.add(new Pair(node,colours[node]));
             }
           }
         }

      }
      

         return true;
    }
}