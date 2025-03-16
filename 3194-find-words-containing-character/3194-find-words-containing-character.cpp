class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> result;
        for (int i = 0; i < words.size(); i++) {
            if (words[i].find(x) != string::npos) { // Check if x is in words[i]
                result.push_back(i);
            }
        }
        return result;
    }
};

