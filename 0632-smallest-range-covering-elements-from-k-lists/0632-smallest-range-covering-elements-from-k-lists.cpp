class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int maxi = INT_MIN,a,b;
        vector<int>ans(2);
        vector<pair<int,pair<int,int>>>temp;
        for(int i=0;i<nums.size();i++){
          temp.push_back(make_pair(nums[i][0],make_pair(i,0)));
          maxi = max(maxi,nums[i][0]);
        }
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq(temp.begin(),temp.end());

       pair<int,pair<int,int>>tem;
       int elem,i,j;
       int mini = pq.top().first;
       ans[0] = mini;
       ans[1] = maxi;

       
        while(pq.size() == nums.size()){
            tem = pq.top();
            pq.pop();
             elem = tem.first;
             i = tem.second.first;
              j = tem.second.second;
          
           if(j+1 < nums[i].size()){
            j++;
             pq.push(make_pair(nums[i][j],make_pair(i,j)));
              maxi = max(maxi,nums[i][j]);
              mini = pq.top().first;
           if((maxi - mini) < (ans[1]-ans[0]))
          { ans[0] = mini; ans[1] = maxi;}
           }else break;
        }
        return ans;
        
    

    }
};