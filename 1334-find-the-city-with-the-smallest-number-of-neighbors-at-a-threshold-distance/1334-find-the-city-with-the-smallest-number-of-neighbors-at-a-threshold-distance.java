class Solution {

    
    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
       

        int[][] dist = new int[n][n];
        for(int[]a : dist){
           Arrays.fill(a,10000000);
        }
        int mini =1000000, cnt =0;
        for(int i=0;i<edges.length;i++){
          dist[edges[i][0]][edges[i][1]] = edges[i][2];
          dist[edges[i][1]][edges[i][0]] = edges[i][2];
        }
         for(int i = 0; i < n; i++){
            dist[i][i] = 0;
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
       int ans =-1;
        for(int i=0;i<n;i++){
            cnt = 0;
            for(int j=0;j<n;j++){
                if( dist[i][j] <= distanceThreshold){
                    cnt++;
                    
                }
            }
            if(cnt <= mini){
                mini = cnt;
                ans = i;
            }
        }

        

        return ans;
    }
}