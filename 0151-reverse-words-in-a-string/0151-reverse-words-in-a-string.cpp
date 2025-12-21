class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int st = 0;
        int i = 0;
        string ans;
        while(i < s.size()){
            while(i<s.size() && s[i] == ' '){
                i++;
            }

            if(i>= s.size()) break;
            int st = i;
            while(i<s.size() && s[i] != ' '){
              i++;
            }
            int len = i - st;
            string word = s.substr(st,len);
            reverse(word.begin(), word.end());
            ans += word;
            ans += " ";
        }
        return ans.substr(0, ans.size()-1);
    }
};