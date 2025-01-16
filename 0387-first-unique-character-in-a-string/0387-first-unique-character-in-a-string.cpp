class Solution {
public:
    int firstUniqChar(string s) {
         vector<int>arr(26,0);
         int i=0;
        while(s[i]!='\0'){
               arr[s[i]-'a']++; i++;
        }
        for(int i =0 ; i<s.size();i++){
            if(arr[s[i] - 'a'] == 1){
                return i;
            }
        }
       
         return -1;

    }
};