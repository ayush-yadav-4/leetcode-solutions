class Solution {
public:
bool check(vector<vector<int>>& graph,vector<int>&color,int start){

 
     if(color[start] != -1) return true;
       queue<int>q;
        q.push(start); 
        color[start] = 1;

        while(!q.empty()){
            int elem = q.front(); q.pop();

            for(auto it: graph[elem]){
               if(color[it] == -1){
                color[it] = !color[elem];
                q.push(it);
               }
               else if(color[it] != -1){
                if(color[it] == color[elem]) return false;
               }
            }
        }
        return true;

}
    bool isBipartite(vector<vector<int>>& graph) {
        
          vector<int>color(graph.size(),-1);
          for(int i=0;i<graph.size();i++){
               if(!check(graph,color,i)){
                 return false;
               }
          }
          return true;
    }
};