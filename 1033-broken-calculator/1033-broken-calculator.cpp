class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int operations = 0;
        while (target > startValue) {
            if (target % 2 == 0) {
                target /= 2;
            } else {
                target += 1;
            }
            operations++;
        }
        // Add the remaining difference if target < startValue
        return operations + (startValue - target);
    }
};
