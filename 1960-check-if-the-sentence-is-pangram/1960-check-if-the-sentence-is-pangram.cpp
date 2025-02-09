class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int>arr(26,0);int i=0;
        while(sentence[i]!= '\0'){
           arr[sentence[i] -'a'] = 1;
           i++;
        }
        for(int i=0;i<arr.size();i++){
            if(arr[i] == 0)return false;
        }
        return true;
    }
};