class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans = INT_MIN;
        for(string str: sentences){
            int i=0,count=0;
           while(str[i] != '\0'){
             if(str[i] == ' ')count++;
             i++;
           }
           count++;
           ans = max(ans,count);
        }
        return ans;
    }
};