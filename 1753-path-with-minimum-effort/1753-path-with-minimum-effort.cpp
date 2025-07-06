class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>dist(heights.size(),vector<int>(heights[0].size(),1e9));
       int rows[] = {0,0,-1,+1};
       int cols[] = {-1,+1,0,0};
        pq.push({0,{0,0}});
        while(!pq.empty()){
          auto it = pq.top();
          int diff = it.first;
          int row = it.second.first;
          int col = it.second.second;
          pq.pop();
          if(row == heights.size()-1 && col == heights[0].size()-1) return diff;
          for(int i=0;i<4;i++){
            int newr = row + rows[i];
             int newc = col + cols[i];

   
             if(newr >=0 && newr<heights.size() && newc>=0 && newc<heights[0].size()){     
              int newdiff = max(abs(heights[newr][newc] - heights[row][col]),diff);
              if(newdiff < dist[newr][newc]){
                 dist[newr][newc] = newdiff;
                 pq.push({newdiff,{newr,newc}});
              }
              
             }
          }
        }
        return 0;
    }
};