class Solution {
public:
    int lengthOfLongestSubstring(string s) {
           if (s.empty()) return 0;
        
         int hash[256];
          fill(begin(hash), end(hash), -1);

        int r=0,l=0,size=0,ans=0;
        while(s[r] != '\0'){
            if(hash[s[r]] != -1){
               if(hash[s[r]]>=l){
                l = hash[s[r]]+1;
               }
            }
            ans = max(ans,(r-l+1));
            hash[s[r]] = r;
            r++;
        }
        return ans;
    }
};