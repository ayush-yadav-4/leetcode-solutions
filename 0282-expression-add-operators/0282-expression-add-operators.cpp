class Solution {
public:
    vector<string> result;

    void dfs(string& num, int target, int pos, long eval, long prev, string path) {
        if (pos == num.size()) {
            if (eval == target) result.push_back(path);
            return;
        }

        for (int i = pos; i < num.size(); ++i) {
            // Avoid numbers with leading zero
            if (i != pos && num[pos] == '0') break;

            string currStr = num.substr(pos, i - pos + 1);
            long curr = stol(currStr);

            if (pos == 0) {
                // First number (no operator before it)
                dfs(num, target, i + 1, curr, curr, currStr);
            } else {
                dfs(num, target, i + 1, eval + curr, curr, path + "+" + currStr);
                dfs(num, target, i + 1, eval - curr, -curr, path + "-" + currStr);
                dfs(num, target, i + 1, eval - prev + prev * curr, prev * curr, path + "*" + currStr);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        if (num.empty()) return {};
        dfs(num, target, 0, 0, 0, "");
        return result;
    }
};
