class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        vector<int> mod0, mod1, mod2;
        int totalSum = 0;

        for (int d : digits) {
            totalSum += d;
            if (d % 3 == 0) mod0.push_back(d);
            else if (d % 3 == 1) mod1.push_back(d);
            else mod2.push_back(d);
        }

        // Sort mod1 and mod2 for easy removal of smallest elements
        sort(mod1.begin(), mod1.end());
        sort(mod2.begin(), mod2.end());

        if (totalSum % 3 == 1) {
            if (!mod1.empty()) mod1.erase(mod1.begin());
            else if (mod2.size() >= 2) mod2.erase(mod2.begin(), mod2.begin() + 2);
            else return "";
        } else if (totalSum % 3 == 2) {
            if (!mod2.empty()) mod2.erase(mod2.begin());
            else if (mod1.size() >= 2) mod1.erase(mod1.begin(), mod1.begin() + 2);
            else return "";
        }

        // Combine all digits and sort in descending order
        vector<int> result;
        result.insert(result.end(), mod0.begin(), mod0.end());
        result.insert(result.end(), mod1.begin(), mod1.end());
        result.insert(result.end(), mod2.begin(), mod2.end());

        if (result.empty()) return "";

        sort(result.rbegin(), result.rend());

        // If first digit is 0, all are 0
        if (result[0] == 0) return "0";

        string res;
        for (int d : result) res += to_string(d);
        return res;
    }
};
