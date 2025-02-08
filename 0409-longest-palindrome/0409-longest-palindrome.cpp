class Solution {
public:
    int longestPalindrome(string s) {
      unordered_map<char,int>mp; int ans=0,count=0;
        for(char a: s){
          mp[a]++;
        }
        for(auto i:mp){
            if(i.second == 1){
                count =1;
            }
            else if(i.second%2 == 1 && i.second >1){
                ans += i.second-1;
                count = 1;
            }
           else ans += i.second;
        }
        if(count == 1) ans = ans+1;
        return ans;
    }
};