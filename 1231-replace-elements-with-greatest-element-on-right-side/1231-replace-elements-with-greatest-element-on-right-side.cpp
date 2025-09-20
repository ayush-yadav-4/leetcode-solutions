class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
         vector<int> ans;
         ans.push_back(-1);
         int elem = arr[arr.size()-1];
         for(int i=arr.size()-2;i>=0;i--){
             
              
              
               ans.push_back(elem);
                elem = max(elem,arr[i]);

         }
         reverse(ans.begin(),ans.end());
         return ans;
    }
};