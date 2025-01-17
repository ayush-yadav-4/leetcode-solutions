class Solution {
public:

    string longestCommonPrefix(vector<string>& strs) {
        string sub = strs[0]; int size = strs.size(); 
        for(int i =1; i< strs.size();i++){
            while(strs[i].find(sub) != 0){
                sub = sub.substr(0,sub.size()-1);
            }
            if(sub.size() == 0) return "";
        }
        return sub;
    }
};