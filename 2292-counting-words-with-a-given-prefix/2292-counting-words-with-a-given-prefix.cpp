class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for(string s:words){
            if(s.find(pref) != string::npos)if(s.find(pref) == 0)ans++;
        }
        return ans;
    }
};