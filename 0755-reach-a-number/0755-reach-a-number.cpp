class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);  // problem is symmetric for negative targets
        int sum = 0;
        int steps = 0;

        while (sum < target || (sum - target) % 2 != 0) {
            steps++;
            sum += steps;
        }

        return steps;
    }
};
