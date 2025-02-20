class Solution {
public:

   void lsp_table(vector<int>&lsp,string s){
     int prefix = 0,suffix=1;
     while(suffix < s.size()){
       if(s[prefix] == s[suffix]){
        lsp[suffix] = prefix+1;
        prefix++; suffix++;
       }
       else{
        if(prefix == 0){
            lsp[suffix] = 0; suffix++;
        }else{
            prefix = lsp[prefix-1];
        }
       }
     }
   }

   bool string_match(string s1,string s2,vector<int>&lsp){
   lsp_table(lsp,s2);
   int first=0,second=0;
    while(first<s1.size() && second < s2.size()){
         if(s1[first] == s2[second]){
            first++; second++;
         }
         else{
           if(second == 0){
            first++;
           }else{
            second = lsp[second-1];
           }
         }
    }

    if(second == s2.size()) return true;
    return false;
   }
    int repeatedStringMatch(string a, string b) {
             int min_repeats = (b.size() + a.size() - 1) / a.size(); 
        int max_repeats = min_repeats + 2; 
        
        string s1 = a;
        vector<int>lsp(b.size(), 0);
        
        for(int count = 1; count <= max_repeats; count++){
            if(string_match(s1, b, lsp)) return count;
            s1 += a;
        }
        return -1;
    }
};