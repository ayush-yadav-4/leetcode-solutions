class Solution {
public:
    vector<int> getClosest(int n) {
        for (int i = sqrt(n); i >= 1; --i) {
            if (n % i == 0) {
                return {i, n / i};
            }
        }
        return {};
    }

    vector<int> closestDivisors(int num) {
        vector<int> option1 = getClosest(num + 1);
        vector<int> option2 = getClosest(num + 2);

        int diff1 = abs(option1[0] - option1[1]);
        int diff2 = abs(option2[0] - option2[1]);

        return (diff1 <= diff2) ? option1 : option2;
    }
};
