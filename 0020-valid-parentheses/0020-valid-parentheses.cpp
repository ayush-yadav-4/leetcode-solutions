class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int i=0;
        while(s[i] != '\0'){
            char a = s[i];
            if(a == '(' || a == '[' || a == '{'){
                st.push(a);
            }
            else if(a == ')' || a == ']' || a=='}'){
            if(st.empty()) return false;
            if((a == ')' && st.top() == '(') || (a == ']' && st.top() == '[') ||(a == '}' && st.top() == '{')){
                st.pop();
            }
            else {return false;}}
            i++;
        }
        if(st.empty()) return true;
        return false;
    }
};