class Solution {
public:
    string sortVowels(string s) {
        vector<int>upper(26,0);
         vector<int>lower(26,0);
         string ans;
         int start =0, second =0,i=0;
        while(i < s.size()){

            if(s[i] == 'a'|| s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
               lower[s[i]-'a']++;
               s[i] = '#';
            }
              
            else if(s[i] == 'A'|| s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
                upper[s[i]-'A']++;
                s[i] = '#';
            }
            i++;
        }

       for(int i =0 ; i < 26 ; i++){
          char c = 'A' + i;
          while(upper[i]){
            ans += c;
            upper[i]--;
          }
       }

         for(int i =0 ; i < 26 ; i++){
          char c = 'a' + i;
          while(lower[i]){
            ans += c;
            lower[i]--;
          }
       }

       while(start < s.size()){
          if(s[start] == '#'){
            s[start] = ans[second];
             second++;
          }
          start++;
       }
        return s;
    }
};