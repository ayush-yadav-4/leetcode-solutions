class Solution {
public:
   void getwords(string s, vector<string>&words){
     string word = "";
     for(char c : s){
        if(c == ' '){
            if(word != ""){
                words.push_back(word);
                word = "";
            }
        }
        else{
          word += c;
        }
     }

     if(word != "") words.push_back(word);
   }
    bool wordPattern(string pattern, string s) {
      vector<string>words;
      getwords(s,words);
      if(pattern.size() != words.size())return false;
    
      unordered_map<string , char>wordtochar;
       unordered_map<char,string>chartoword;

      for(int i=0;i<pattern.size();i++){
         string word = words[i];
         char c = pattern[i];

         if(chartoword.find(c) != chartoword.end()){
            if(chartoword[c] != word) return false;

         }
         
         if(wordtochar.find(word) != wordtochar.end()){
            if(wordtochar[word] != c) return false;

         }

         wordtochar[word] = c;
         chartoword[c] = word;



      }
      return true;

    }
};