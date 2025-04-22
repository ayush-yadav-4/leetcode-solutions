class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
         std::unordered_map<char, int> charCount;
        for (char c : chars) {
            charCount[c]++;
        }

        int totalLength = 0;

        // Iterate through each word in words
        for (const std::string& word : words) {
            // Create a frequency map for the current word
            std::unordered_map<char, int> wordCount;
            for (char c : word) {
                wordCount[c]++;
            }

            // Check if the word can be formed with characters in chars
            bool isGood = true;
            for (const auto& entry : wordCount) {
                char c = entry.first;
                int count = entry.second;

                if (charCount[c] < count) {
                    isGood = false;  // If there are not enough characters, mark it as not good
                    break;
                }
            }

            // If the word is good, add its length to the total length
            if (isGood) {
                totalLength += word.length();
            }
        }

        return totalLength;
    }
};