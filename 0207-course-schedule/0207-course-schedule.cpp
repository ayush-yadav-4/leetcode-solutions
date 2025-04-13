class Solution {
public:
  bool loop(vector<vector<int>>& graph,vector<int>&visited,int idx){
    if(visited[idx] == 1) return false; // currently processing and Loop detect
    if(visited[idx] == 2) return true;
     visited[idx] = 1;
    for(auto it : graph[idx]){

         if(loop(graph,visited,it) == false) return false;
         
           
        
    }
    visited[idx] = 2;
     return true;

  }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>visited(numCourses,0);
     
        vector<vector<int>>adj(numCourses);

        for(int i=0;i<prerequisites.size();i++){
          int u = prerequisites[i][0];
          int v = prerequisites[i][1];
          adj[u].push_back(v);
        }

        for(int i=0;i<numCourses;i++){
        
                if(loop(adj,visited,i) == false) return false;
            
        }
       
        return true;
    }
};