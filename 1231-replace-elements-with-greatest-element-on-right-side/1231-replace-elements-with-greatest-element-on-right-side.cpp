class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
         vector<int>ans(arr.size(),-1);
         int elem  = arr[arr.size()-1];
         arr[arr.size()-1] = arr[arr.size()-1];
        for(int i=arr.size()-2;i>=0;i--){
           elem = max(elem,arr[i+1]);
           ans[i] = elem;
        }
        return ans;
    }
};