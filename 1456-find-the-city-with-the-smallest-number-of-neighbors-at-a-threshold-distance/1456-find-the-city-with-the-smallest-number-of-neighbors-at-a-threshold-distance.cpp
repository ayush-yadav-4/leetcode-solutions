class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));

        for(int i=0;i<edges.size();i++){
            dist[edges[i][0]][edges[i][1]] = edges[i][2];
              dist[edges[i][1]][edges[i][0]] = edges[i][2];
        }
       for(int i=0;i<n;i++){
        dist[i][i] = 0;
       }

        for(int via = 0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                  if(dist[i][via] < INT_MAX && dist[via][j] < INT_MAX){
      dist[i][j] = min(dist[i][j],(dist[i][via]+dist[via][j]));
                  }
                   
                }
            }
        }

        int cnt = 0,city = -1,maxcity = n;
        for(int i=0;i<n;i++){
            cnt = 0;
         for(int j=0;j<n;j++){
           if(dist[i][j] <= distanceThreshold && dist[i][j] != 0){
            cnt++;
            
           }
           
         }
        if(cnt <= maxcity){
            maxcity = cnt;
            city = i;
           }
        }

        return city;
    }
};