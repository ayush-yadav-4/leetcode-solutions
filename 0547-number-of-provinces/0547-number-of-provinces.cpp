class Solution {
public:
void dfs(int idx , vector<vector<int>>& isConnected,vector<int>& visited){
    visited[idx] = 1;
    for(int i=0;i<isConnected[0].size();i++){
        if(i != idx && isConnected[idx][i] == 1 && visited[i] == 0){       
            visited[i] = 1;
            dfs(i,isConnected,visited);
 }
    }
    
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int>visited(isConnected.size(),0);
        int ans = 0;
        
        
        for(int i =0 ;i<isConnected.size();i++){
            if(visited[i] == 0){ ans++;
            dfs(i,isConnected,visited);
            }
        }
        return ans;
    }
};