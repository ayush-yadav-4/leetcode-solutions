class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream ss(sentence); // Split the sentence into words
        string word;
        int index = 0;
        
        while (ss >> word) {  // Read each word
            index++;
            if (word.find(searchWord) == 0) { // Check if searchWord is a prefix
                return index;
            }
        }
        
        return -1; // Return -1 if no word has searchWord as a prefix
    }
};
