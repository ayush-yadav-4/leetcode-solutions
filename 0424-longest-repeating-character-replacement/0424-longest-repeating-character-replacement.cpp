class Solution {
public:
    int characterReplacement(string s, int k) {
        if(k == s.length())return s.size();
        int ans=0,maxf=0,i=0,l=0;
        int hash[26] = { 0 };
        while(s[i]!= '\0'){
             hash[s[i]-'A']++;
             maxf = max(maxf,hash[s[i]-'A']);

             while((i-l+1 - maxf) > k){
                hash[s[l]-'A']--;l++;
             }

             if((i-l+1 - maxf) <= k){
              ans = max(ans,i-l+1);
             }
             i++;
        }
        return ans;
    }
};