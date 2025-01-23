class Solution {

   
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<int,int>mp; int ans=0,prefix=0;
       for(int i=0;i<nums.size();i++){
            prefix += nums[i];
            if(prefix == goal){
                ans++;
            }
            if(mp.find(prefix-goal) != mp.end()){
                ans += mp[prefix-goal];
            }
                mp[prefix]++;
            
       }
       return ans;
    }
};