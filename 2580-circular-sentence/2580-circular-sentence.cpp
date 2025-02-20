class Solution {
public:
    bool isCircularSentence(string sentence) {
        int i=0;
        if(sentence[0] != sentence[sentence.size()-1])return false;
        while(sentence[i]!= '\0'){
           if(sentence[i] == ' '){
             if(sentence[i-1] != sentence[i+1]) return false;
           }
           i++;
        }
        return true;
    }
};