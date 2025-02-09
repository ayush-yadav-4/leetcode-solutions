class Solution {
public:
    string defangIPaddr(string address) {
        string ans;int i=0;
        while(address[i] != '\0'){
            if(address[i] == '.'){
                ans +="[.]";
                
                   i++;
            }else{
                ans.push_back(address[i]);
                i++;
            }
        }
        return ans;
    }
};