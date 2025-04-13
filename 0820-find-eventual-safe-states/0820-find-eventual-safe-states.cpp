class Solution {
public:
 bool isloop(vector<vector<int>>& graph,vector<int>&visited,vector<int>&pathvis,vector<int>& check,int elem){
visited[elem] = 1;
pathvis[elem] = 1;
 check[elem] = 0;
 for(auto it:graph[elem]){
   if(visited[it] == 0){
     if(isloop(graph,visited,pathvis,check,it) == true){
        check[elem] = 0;
        return true;
     }
   }
     else if(pathvis[it] == 1){
        check[elem] = 0;
        return true;
     }
   }
 
 check[elem] = 1;
 pathvis[elem] = 0;
 return false;
 }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>visited(graph.size(),0);
        vector<int>check(graph.size(),0);
        vector<int>pathvis(graph.size(),0);


        for(int i=0;i<graph.size();i++){
         if(visited[i] == 0)
            {isloop(graph,visited,pathvis,check,i);}
           
        }
        vector<int>ans;
        for(int i=0;i<check.size();i++){
          if(check[i] == 1)ans.push_back(i);
        }

       
        return ans;
    }
};