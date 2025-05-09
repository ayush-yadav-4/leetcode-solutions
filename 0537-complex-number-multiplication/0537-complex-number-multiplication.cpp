class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        // Helper lambda to parse the complex number
        auto parse = [](string s) -> pair<int, int> {
            int plus = s.find('+');
            int real = stoi(s.substr(0, plus));
            int imag = stoi(s.substr(plus + 1, s.length() - plus - 2)); // Remove 'i' at the end
            return {real, imag};
        };
        
        auto [a, b] = parse(num1);
        auto [c, d] = parse(num2);
        
        int realPart = a * c - b * d;
        int imagPart = a * d + b * c;
        
        return to_string(realPart) + "+" + to_string(imagPart) + "i";
    }
};
