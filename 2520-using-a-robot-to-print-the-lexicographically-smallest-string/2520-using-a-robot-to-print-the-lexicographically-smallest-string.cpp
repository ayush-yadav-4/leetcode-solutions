class Solution {
public:
    string robotWithString(string s) {
        vector<int> freq(26, 0);  // frequency of characters in s

        // Step 1: Count frequency of each character
        for (char c : s) {
            freq[c - 'a']++;
        }

        string t = "";  // stack (implemented as a string)
        string res = ""; // final result

        int i = 0; // pointer to traverse s
        int minCharIndex = 0; // smallest character index remaining in s

        for (char c : s) {
            t.push_back(c);            // push to robot's stack
            freq[c - 'a']--;           // reduce freq from s

            // update the smallest character remaining in s
            while (minCharIndex < 26 && freq[minCharIndex] == 0)
                minCharIndex++;

            // pop from t while top <= minCharRemaining
            while (!t.empty() && (t.back() - 'a') <= minCharIndex) {
                res += t.back();       // write to paper
                t.pop_back();          // remove from stack
            }
        }

        // pop remaining from stack
        while (!t.empty()) {
            res += t.back();
            t.pop_back();
        }

        return res;
    }
};
