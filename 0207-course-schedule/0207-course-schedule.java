class Solution {
    boolean DFS(List<List<Integer>> ls,int src,int[] vis, int[] pathvis){
      vis[src] = 1;
      pathvis[src] = 1;

      for(int i=0;i<ls.get(src).size();i++){
          int node = ls.get(src).get(i);
          if(vis[node] == 0){
            if(DFS(ls,node,vis,pathvis)) return true;
          }
          else if(pathvis[node] == 1) return true;
      }
      pathvis[src] = 0;
      return false;
    }
    public boolean canFinish(int num, int[][] grid) {
        List<List<Integer>> ls = new ArrayList<>();
        int[] vis = new int[num];
        int[] pathvis = new int[num];
        Arrays.fill(vis,0);
        Arrays.fill(pathvis,0);
        for(int i=0;i<num;i++){
          ls.add(new ArrayList<>());
        }
        for(int i=0;i<grid.length;i++){
          ls.get(grid[i][1]).add(grid[i][0]);
        }

        for(int i=0;i<num;i++){
          if(vis[i] == 0){
            if(DFS(ls,i,vis,pathvis)) return false;
          }
        }

        return true;

    }
}