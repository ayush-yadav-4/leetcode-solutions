class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        vector<int>nge(nums2.size(),-1); vector<int>ans;
        st.push(nums2[nums2.size()-1]);
        for(int i =nums2.size()-2;i>=0;i--){
             while(!st.empty() && st.top()<=nums2[i]){
                    st.pop();
                }
            if(!st.empty()) nge[i] = st.top();
            st.push(nums2[i]); 
        }

        for(int i =0 ; i<nums1.size();i++){
            for(int j =0 ; j<nums2.size();j++){
               if(nums1[i] == nums2[j]){
                ans.push_back(nge[j]);
               }
            }
        }
        return ans;

    }
};