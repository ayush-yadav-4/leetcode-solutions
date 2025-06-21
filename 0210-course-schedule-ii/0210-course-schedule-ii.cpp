class Solution {
public:
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
    vector<int> findOrder(int V, vector<vector<int>>& pre) {
         vector<int>adj[V];
        vector<int>indeg(V,0);
        vector<int>vis(V,0);
        vector<int>pathvis(V,0);
        vector<int>ans;
        for(int i=0;i<pre.size();i++){
          adj[pre[i][1]].push_back(pre[i][0]);
          
        }

        for(int i=0;i<V;i++){
            if(!vis[i]){
            if(DFS(adj,vis,pathvis,i)) return ans;
          }
        }

        for(int i=0;i<V;i++){
            for(auto it : adj[i]){
                indeg[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<indeg.size();i++){
          if(indeg[i] == 0){
            q.push(i);
          }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto it : adj[node]){
               indeg[it]--;
               if(indeg[it] == 0) q.push(it);
            }
        }
        return ans;
    }
};