class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>mp;
         int ans =0, majority = nums.size()/2;
        for(int i =0; i < nums.size() ; i++){
            mp[nums[i]]++;
        }
         for(auto it = mp.begin(); it != mp.end();it++){
           if(it->second > majority){
            ans = it->first;
           }
        }
        return ans;
    }
};