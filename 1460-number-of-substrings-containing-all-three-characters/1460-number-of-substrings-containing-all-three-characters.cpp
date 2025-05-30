class Solution {
public:
    int numberOfSubstrings(string s) {
       int ans=0;
       int idx[3] = {-1,-1,-1}; 
       //int hash[3];

       for(int i=0;i<s.size();i++){
         // hash[s[i] - 'a'] = 1;
         idx[s[i] - 'a'] = i;
       // if(hash[0] != -1 && hash[1] != -1 && hash[2]!= -1)
         ans+= 1 + min(idx[0],min(idx[1],idx[2]));

       }
       return ans;
    }
};