class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int cnt=0,prefix=0,elem = 0;
        mp[0] = 1;
        for(int i=0;i<nums.size();i++){
        
          prefix += nums[i];
          elem = (prefix % k);
          if (elem < 0) elem += k;

          if(mp.find(elem) != mp.end()){
                  cnt+=mp[elem];
          }
          mp[elem]++;
        }
        return cnt;
    }
};