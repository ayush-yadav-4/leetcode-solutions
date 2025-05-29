class Solution {
public:
    string removeKdigits(string num, int k) {
       if(num.size() == k) return "0";
       int size = k;
       stack<int>st; string ans; int i=0;
       while(num[i] != '\0'){
  
            while(!st.empty() && st.top() > (int)num[i] && size >0){
              st.pop(); size--;
            }
            if(size == 0) break;
            st.push((int)num[i]);
      
         i++;
       }
       while(i<num.size()){
        st.push((int)num[i]);
        i++;
       }

       if(size > 0){
        while(size--){
            st.pop();
        }
       }

       while(!st.empty()){
        ans += (char)st.top();
        st.pop();
       }

       reverse(ans.begin(),ans.end());
       i=0;
       if(ans[i] == '0'){
       while(ans[i] == '0'){
        i++;
       }
       ans = ans.substr(i);
       }
       if(ans.size() == 0) return "0";
       return ans;


    }
};