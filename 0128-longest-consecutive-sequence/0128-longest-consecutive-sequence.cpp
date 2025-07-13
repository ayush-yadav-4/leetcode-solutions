class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        int cnt = 1,elem=0,ans=0;
        for(int i=0;i<nums.size();i++){
          st.insert(nums[i]);
        }
        for(int i : st){
            if(st.find(i-1) == st.end()){
               cnt = 1;
               elem = i;
               while(st.find(elem+1) != st.end()){
                elem = elem + 1;
                cnt++;
               }
               ans = max(ans,cnt);
            }
        }
        return ans;
    }
};