class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>>st;
         st.push({s[0],1});
          int i = 1;
         while(i<s.size()){
           char c = s[i];
           if(!st.empty() && st.top().first == c){
            if(st.top().second + 1 == k){
                while(!st.empty() && st.top().first == c){
                   st.pop();
                }
            }
            else{
                st.push({c,st.top().second+1});
            }
           }
           else{
            st.push({c,1});
           }
           i++;
         }
        string str;
         while(!st.empty()){
            str += st.top().first;
            st.pop();
         }
         reverse(str.begin(), str.end());
        return str;
    }
};