class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        vector<int>ans(arr.size(),0);
        stack<pair<int,int>>st;
        int n = arr.size();
        st.push({arr[n-1],n-1});
        for(int i = arr.size()-2;i>=0;i--){
           while(!st.empty() && st.top().first <= arr[i]){
            st.pop();
           }
           if(st.empty()){
            ans[i] = 0;
           }
           else{
            ans[i] = st.top().second - i;
            
           }
           st.push({arr[i], i});
        }
        return ans;
    }
};