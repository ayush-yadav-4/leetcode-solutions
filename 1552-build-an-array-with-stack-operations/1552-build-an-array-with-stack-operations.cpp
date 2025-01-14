class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>arr; int a=1,i=0;
        while(a<=n){
             if(a == target[i]){
                 arr.push_back("Push");
                 a++;i++;
             }
             if(i == target.size()) return arr;
              if(a != target[i] ){
                 arr.push_back("Push");
                arr.push_back("Pop");
                a++;
             }
            
        }
        return arr;

    }
};