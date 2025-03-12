class Solution {
public:
    int signFunc(int x) {
        if (x > 0) return 1;
        if (x < 0) return -1;
        return 0;
    }

    int arraySign(vector<int>& nums) {
        int sign = 1;
        for (int num : nums) {
            if (num == 0) return 0; 
            if (num < 0) sign = -sign;
        }
        return sign;
    }
};
