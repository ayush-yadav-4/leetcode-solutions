class Solution {
public:
    string solveEquation(string equation) {
        // Helper function to parse the side of the equation
        auto parse = [](const string& s) {
            int xCoeff = 0, constant = 0, sign = 1, n = s.size(), i = 0;
            while (i < n) {
                // Handle the current term
                if (s[i] == '+') {
                    sign = 1;
                    i++;
                } else if (s[i] == '-') {
                    sign = -1;
                    i++;
                }

                int num = 0;
                bool hasNum = false;
                while (i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    hasNum = true;
                    i++;
                }

                if (i < n && s[i] == 'x') {  // Found 'x'
                    if (hasNum) {
                        xCoeff += sign * num;
                    } else {
                        xCoeff += sign * 1;  // Implicit 1 for 'x'
                    }
                    i++;  // Skip the 'x'
                } else {  // Constant term
                    if (hasNum) {
                        constant += sign * num;
                    } else {
                        constant += sign * 0;
                    }
                }
            }
            return make_pair(xCoeff, constant);
        };

        // Split the equation at '='
        int idx = equation.find('=');
        string left = equation.substr(0, idx);
        string right = equation.substr(idx + 1);

        // Parse both sides
        auto [leftX, leftConst] = parse(left);
        auto [rightX, rightConst] = parse(right);

        // Combine the results
        int xCoeff = leftX - rightX;
        int constant = rightConst - leftConst;

        // Handle the possible outcomes
        if (xCoeff == 0) {
            if (constant == 0) {
                return "Infinite solutions";
            } else {
                return "No solution";
            }
        }

        // Solve for x
        return "x=" + to_string(constant / xCoeff);
    }
};
