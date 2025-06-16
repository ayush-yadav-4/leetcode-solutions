class Solution {
public:
    int longestPalindrome(string s) {
                map<char,int>mp;
        int ans = 0,cnt=0;
        for(int i=0;i<s.size();i++){
          mp[s[i]]++;
        }
         for(auto it:mp){
         if(it.second % 2 == 0){
            ans += it.second;
         }else if(it.second%2 == 1){
           ans += (it.second-1); 
           cnt = 1;
         }
        }

        if(cnt == 1) return ans+1;
        return ans;
    }
};