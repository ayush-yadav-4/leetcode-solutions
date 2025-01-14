class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k == num.size()) return "0";
        int i=0; string ans; stack<int>st;
        
                while(num[i] != '\0'){
           int a = (int)num[i];
           while(!st.empty() && st.top()>a && k>0){
             st.pop(); k--;
           }
           st.push(a); i++;
        }
        if(k>0){
            while(!st.empty() && k>0){
                st.pop(); k--;
            }
        }
        while(!st.empty()){
           char a = (char)st.top();
           ans.push_back(a);
           st.pop();
        }
        reverse(ans.begin(),ans.end());
       
        while(!ans.empty() && ans[0] == '0'){
            ans.erase(0,1);
         
           
        }
           if(ans.empty()) return "0";
        return ans;
    }
};