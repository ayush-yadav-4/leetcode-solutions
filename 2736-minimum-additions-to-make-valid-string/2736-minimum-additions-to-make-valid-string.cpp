class Solution {
public:
    int addMinimum(string word) {
 
       int i=0,req=0;
        while(i<word.size()){
           int valid=0;
           if(word[i] == 'a'){
             valid++; i++;
           }
           if(i<word.size() && word[i] == 'b'){
              valid++; i++;
           }
           if(i<word.size() && word[i] == 'c'){
             valid++;i++;
           }
    

           req += 3- valid;
        }
        return req;
    }
};