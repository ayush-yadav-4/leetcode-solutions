class Solution {
public:
    string removeDuplicates(string s) {
         stack<char>st;
        int i=1;
        st.push(s[0]);
        while(i<s.size()){
            char c = s[i];
            
            if(!st.empty() && st.top() == c){
                st.pop();
            }
            else{
                st.push(c);
            }
           i++;
        }
        string str;
        while(!st.empty()){
            str += st.top();
            st.pop();
        }
        reverse(str.begin(), str.end());
        return str;
    }
};