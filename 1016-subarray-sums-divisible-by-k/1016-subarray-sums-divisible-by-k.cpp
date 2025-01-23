class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int prefix =0,ans=0,target=0;
        map<int,int>mp;

        for(int i=0;i<nums.size();i++){
            prefix += nums[i];
            if(prefix%k == 0) ans++;
            target = prefix%k;
             if(target<0) target = target+k;
            if(mp.find(target) != mp.end() ){
                ans+= mp[target];
            }
           
            mp[target]++;

        }
        return ans;
    }
};