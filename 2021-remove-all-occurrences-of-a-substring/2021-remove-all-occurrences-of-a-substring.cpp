class Solution {
public:
    string removeOccurrences(string s, string part) {
        int size = part.size(); int start =0;
        while(s.length()> 0 && s.find(part)<s.length()){
           start = s.find(part);
           s = s.erase(start,size);

        }
        return s;
    }
};