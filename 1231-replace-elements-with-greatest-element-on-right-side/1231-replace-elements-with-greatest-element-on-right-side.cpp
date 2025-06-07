class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int elem = arr[arr.size()-1];
        vector<int>ans(arr.size(),-1);
        for(int i= arr.size()-2;i>=0;i--){
           ans[i] = elem;
            elem = max(elem,arr[i]);
        } 
        return ans;
    }
};