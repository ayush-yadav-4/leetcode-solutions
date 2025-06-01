class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
       sort(g.begin(),g.end());   sort(s.begin(),s.end());
       int r=0,l=0;
       while(r<s.size() && l<g.size()){
         if(g[l]<=s[r]) l+=1;
         r++;
       }
       return l;
    }
};