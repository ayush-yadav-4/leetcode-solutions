class Solution {
public:
    int majorityElement(vector<int>& arr) {
         int cnt=0,elem=0;
        for(int i=0;i<arr.size();i++){
            if(cnt == 0){
                elem = arr[i];
                cnt++;
            }
           else if(arr[i] == elem){
            cnt++;
           }
           else {
             cnt--;
           }
        }
        return elem;
    }
};