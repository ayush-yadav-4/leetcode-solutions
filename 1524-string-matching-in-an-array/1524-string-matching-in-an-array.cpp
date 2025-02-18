class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        
        vector<string>ans;
        for(string c:words){
        for(string s:words){
            if(s.find(c) != string::npos && c != s){ ans.push_back(c);break;}

        }
        }
        return ans;
    
    }
};