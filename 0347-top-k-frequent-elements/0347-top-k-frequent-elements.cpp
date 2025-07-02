class Solution {
public:
 static bool cmp(pair<int,int>&a,pair<int,int>&b){
  return a.second > b.second;
}
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        vector<int>ans;
    
        for(int i=0;i<nums.size();i++){
          mp[nums[i]]++;
          
        }
        vector<pair<int,int>>freq(mp.begin(),mp.end());
        sort(freq.begin(),freq.end(),cmp);
       
       for(auto it :freq ){
         if(k == 0) return ans;
          ans.push_back(it.first);
          k--;
      
       
        }

        return ans;
    }
};