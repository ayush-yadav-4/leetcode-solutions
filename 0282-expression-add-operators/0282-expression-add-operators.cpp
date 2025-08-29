class Solution {
public:
    vector<string> result;
    
    void backtrack(string &num, int target, int pos, long calc, long tail, string expr) {
        if (pos == num.size()) {
            if (calc == target) {
                result.push_back(expr);
            }
            return;
        }
        
        for (int i = pos; i < num.size(); i++) {
            // avoid numbers with leading zeros
            if (i != pos && num[pos] == '0') break;
            
            string currStr = num.substr(pos, i - pos + 1);
            long currNum = stol(currStr);
            
            if (pos == 0) {
                // First number, just take it without operator
                backtrack(num, target, i + 1, currNum, currNum, currStr);
            } else {
                // '+'
                backtrack(num, target, i + 1, calc + currNum, currNum, expr + "+" + currStr);
                // '-'
                backtrack(num, target, i + 1, calc - currNum, -currNum, expr + "-" + currStr);
                // '*'
                backtrack(num, target, i + 1, calc - tail + tail * currNum, tail * currNum, expr + "*" + currStr);
            }
        }
    }
    
    vector<string> addOperators(string num, int target) {
        backtrack(num, target, 0, 0, 0, "");
        return result;
    }
};
