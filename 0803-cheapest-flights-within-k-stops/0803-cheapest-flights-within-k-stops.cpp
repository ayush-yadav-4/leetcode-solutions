class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       vector<vector<pair<int, int>>> adj(n);
        for(int i=0;i<flights.size();i++){
           adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        
        queue<pair<int,pair<int,int>>>q;
        vector<int>dist(n,1e9);
        dist[src] = 0;
        q.push({0,{src,0}});
      int ans = INT_MAX;
        while(!q.empty()){
          auto it = q.front();
          q.pop();
          int k_val = it.first;
          int node = it.second.first;
          int wt = it.second.second;
         if(k_val > k) continue;
          for(auto it : adj[node]){

            if(wt + it.second <= dist[it.first] && k_val<=k){
                 dist[it.first] = wt + it.second;
                 q.push({k_val+1,{it.first,dist[it.first]}});

            }
             
          }

        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};