class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char,char>mp1;
        unordered_map<char,char>mp2;

        for(int i =0; i<s.length(); i++){
            char a = t[i];
            char b = s[i];
           if(mp1.count(b) && mp1[b] != a){
           return false;
           }
            if(mp2.count(a) && mp2[a] != b){
               return false;
            }
        
            mp1[b] = a;
            mp2[a] = b;
        }
        return true;
        
    }
};