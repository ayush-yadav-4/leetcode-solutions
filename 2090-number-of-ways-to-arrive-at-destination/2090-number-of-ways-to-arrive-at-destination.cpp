class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);

        for(int i=0;i<roads.size();i++){
          adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
          adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        vector<long long> dist(n, LLONG_MAX);  // Use long long here
        vector<int> count(n, 0);

        pq.push({0,0});
        dist[0] = 0;
        count[0] = 1;
        int mod = (int)(1e9 + 7);

        while(!pq.empty()){
           long long wt = pq.top().first;
           long long  node = pq.top().second;
           pq.pop();

           for(auto it : adj[node]){
            long long int newtime = wt + it.second;
              if(newtime < dist[it.first] ){
                dist[it.first] = wt + it.second;
                count[it.first] = count[node];
                pq.push({wt + it.second,it.first});
              }
              else if(wt + it.second == dist[it.first]){
                count[it.first] = (count[node] + count[it.first])%mod;
              }
           }
        }
        return (count[n-1])%mod;
    }
};