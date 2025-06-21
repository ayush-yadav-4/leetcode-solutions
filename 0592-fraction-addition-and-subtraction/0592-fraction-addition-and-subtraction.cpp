

class Solution {
public:
    string fractionAddition(string expression) {
        int num = 0, den = 1;  // starting with 0/1

        for (int i = 0; i < expression.size(); ) {
            // Parse sign
            int sign = 1;
            if (expression[i] == '+' || expression[i] == '-') {
                sign = (expression[i] == '-') ? -1 : 1;
                i++;
            }

            // Parse numerator
            int numerator = 0;
            while (isdigit(expression[i])) {
                numerator = numerator * 10 + (expression[i++] - '0');
            }

            // Skip '/'
            i++; 

            // Parse denominator
            int denominator = 0;
            while (i < expression.size() && isdigit(expression[i])) {
                denominator = denominator * 10 + (expression[i++] - '0');
            }

            // Add the new fraction to the result
            num = num * denominator + sign * numerator * den;
            den *= denominator;

            // Reduce the result fraction
            int g = gcd(abs(num), den);
            num /= g;
            den /= g;
        }

        return to_string(num) + "/" + to_string(den);
    }
};
