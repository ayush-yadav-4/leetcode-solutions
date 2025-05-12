class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string num = to_string(n);
        int mark = num.size();
        
        // Find the point where the number is no longer monotonic
        for (int i = num.size() - 1; i > 0; --i) {
            if (num[i] < num[i - 1]) {
                mark = i;
                num[i - 1]--;
            }
        }

        // Set all digits after the mark to '9'
        for (int i = mark; i < num.size(); ++i) {
            num[i] = '9';
        }

        return stoi(num);
    }
};
