class Solution {
public:
    string longestPrefix(string s) {
       vector<int>Lsp(s.size(),0);
       int prefix=0,suffix=1;
       while(suffix<s.size()){
        if(s[prefix] == s[suffix]){
            Lsp[suffix] = prefix+1;
            prefix++;suffix++;
        }
        else{

            if(prefix ==0){
                Lsp[suffix] = 0; suffix++;
            }
            else prefix = Lsp[prefix-1];
        }
       }
       
        return s.substr(0,Lsp[Lsp.size()-1]);
    }
};