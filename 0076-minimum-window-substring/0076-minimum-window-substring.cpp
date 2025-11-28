class Solution {
public:
bool check(vector<int>t_freq,vector<int>s_freq ){
  
  for(int i = 0;i< 128;i++){
     if(s_freq[i] < t_freq[i]) return false;
  }
  return true;
}
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";
        if(s == t) return s;
        vector<int>t_freq(128,0);
        vector<int>s_freq(128,0);
       int ans = INT_MAX, st = 0, end = 0,f = 0,l = 0;
        for(int i=0;i<t.size();i++){
           t_freq[t[i]]++;
        }

        while(end < s.size()){
            s_freq[s[end]]++;
           while(check(t_freq,s_freq)){
            if(ans > end-st+1){
                f = st; l = end; ans = end - st +1;
            }
            s_freq[s[st]]--;

            st++;
           }
           end++;
        }
        if(ans == INT_MAX) return "";
        return s.substr(f,l-f+1);
    }
};