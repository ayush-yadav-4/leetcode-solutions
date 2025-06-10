class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int total = a + b + c;
        int maxPile = max({a, b, c});
        return min(total - maxPile, total / 2);
    }
};
