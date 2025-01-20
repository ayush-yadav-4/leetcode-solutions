class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        if(s.size() ==1 &&t.size() == 1){if(s!=t)return false;}
        int j=0;
        for(int i=0;i<s.size()-1;i++){
           if(s[i] != t[i]){
            if(i == s.size()-1)return false;
            j=i+1;
            while(s[i]!=t[i]){
                if(j==s.size()) return false;
               swap(s[i],s[j]); 
               j++;
            }
               
           }
        }
        if(s[s.size()-1]!= t[t.size()-1]) return false;
        return true;
    }
};