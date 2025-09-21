class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        vector<int>hash(256,-1);
        int st =0,end=0,ans = 1;
        while(end<s.size()){
           if(hash[s[end]] != -1){
              if(hash[s[end]]>=st){
                st = hash[s[end]] + 1;
              }
           }

           ans = max(ans,end-st+1);
           hash[s[end]] = end;
           end++;
        }
        return ans;
    }
};