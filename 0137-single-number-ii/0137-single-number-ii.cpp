class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = -1;
        map<int,int>mp;
        for(int i =0; i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto i = mp.begin(); i != mp.end(); i++){
           if(i->second == 1) return i->first;
        }
        return ans;
        
    }
};