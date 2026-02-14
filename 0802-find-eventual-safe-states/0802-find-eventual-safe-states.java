class Solution {

    boolean DFS(int[][] graph,int src,int[] vis,int[] pathvis,int[] check){
    vis[src] = 1;
    pathvis[src] = 1;
    check[src] = 1;
    for(int i=0;i<graph[src].length;i++){
        int node = graph[src][i];
        if(vis[node] == 0){
           
            if(DFS(graph,node,vis,pathvis,check) == true){
                 check[src] = 0;
                return true;
            }
        }
        else if(pathvis[node] == 1){
            check[src] = 0;
            return true;
        }
       
    }

    pathvis[src] = 0;
    check[src] = 1;
    return false;
     
    }
    public List<Integer> eventualSafeNodes(int[][] graph) {
        
   
         List<Integer> ans = new ArrayList<>();
        int[] vis = new int[graph.length];
         int[] pathvis = new int[graph.length];
        int[] check = new int[graph.length];
        Arrays.fill(vis,0);
         Arrays.fill(pathvis,0);
        Arrays.fill(check,1);
    
        for(int i=0;i<graph.length;i++){
           if(vis[i] == 0){
            DFS(graph,i,vis,pathvis,check);
           }
        }

        for(int i=0;i<graph.length;i++){
           if(check[i] == 1){
            ans.add(i);
           }
  
        }
        return ans;

    }
}