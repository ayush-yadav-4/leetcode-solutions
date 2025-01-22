class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<vector<int>>ans(isWater.size(),(vector<int>(isWater[0].size(),INT_MAX-1)));

        for(int i=0;i<isWater.size();i++){
            for(int j=0;j<isWater[0].size();j++){
                if(isWater[i][j] == 1){
                    ans[i][j] = 0;
                    continue;
                }
                else{
             if(j>0){
                    ans[i][j] = min(ans[i][j],ans[i][j-1]+1);
                }
                 if(i>0){
                    ans[i][j] = min(ans[i][j],ans[i-1][j]+1);
                }
                }
            }
        }

          for(int i=isWater.size()-1;i>=0;i--){
            for(int j=isWater[0].size()-1;j>=0;j--){
                if(isWater[i][j] == 1){
                    ans[i][j] = 0;
                }
                else{
                 if(j<isWater[0].size()-1){
                    ans[i][j] = min(ans[i][j],ans[i][j+1]+1);
                }
                 if(i<isWater.size()-1){
                    ans[i][j] = min(ans[i][j],ans[i+1][j]+1);
                }}
            }
        }
        return ans;
    }
};