class Solution {
public:
    // bool loop(vector<vector<int>>& graph, vector<int>& visited, int idx) {
    //     if (visited[idx] == 1)
    //         return false; // currently processing and Loop detect
    //     if (visited[idx] == 2)
    //         return true;
    //     visited[idx] = 1;
    //     for (auto it : graph[idx]) {

    //         if (loop(graph, visited, it) == false)
    //             return false;
    //     }
    //     visited[idx] = 2;
    //     return true;
    // }
    
    bool DFS(vector<int>adj[],vector<int>&vis,vector<int>&pathvis,int node){
    vis[node] = 1;
    pathvis[node] = 1;
    for(auto it : adj[node]){
       if(vis[it] == 1 && pathvis[it] == 1) return true;
       else if(!vis[it]){
        if(DFS(adj,vis,pathvis,it)) return true;
       }
    }
    pathvis[node] = 0;

    return false;
 }
    bool canFinish(int V, vector<vector<int>>& pre) {
        // vector<int> visited(numCourses, 0);

        // vector<vector<int>> adj(numCourses);

        // for (int i = 0; i < prerequisites.size(); i++) {
        //     int u = prerequisites[i][0];
        //     int v = prerequisites[i][1];
        //     adj[u].push_back(v);
        // }

        // for (int i = 0; i < numCourses; i++) {

        //     if (loop(adj, visited, i) == false)
        //         return false;
        // }

        // return true;

            vector<int>adj[V];
        vector<int>vis(V,0);
         vector<int>pathvis(V,0);
        for(int i=0;i<pre.size();i++){
          adj[pre[i][1]].push_back(pre[i][0]);
          
        }

        for(int i=0;i<V;i++){
          if(!vis[i]){
            if(DFS(adj,vis,pathvis,i)) return false;
          }
        }
        return true;
    }
};