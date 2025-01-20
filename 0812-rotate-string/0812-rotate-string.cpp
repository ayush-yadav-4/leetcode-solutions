class Solution {
public:
    bool rotateString(string s, string goal) {
        for(int i=0;i<goal.size();i++){
            if(s == goal) return true;
            for(int i=0;i<s.size()-1;i++){
                swap(s[i],s[i+1]);
            }
        }
        return false;
    }
};