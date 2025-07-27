class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> res;
        int size = 1 << n;

        // Generate standard n-bit Gray code
        for (int i = 0; i < size; ++i) {
            res.push_back(i ^ (i >> 1));
        }

        // Find index of 'start' in the Gray code
        int idx = 0;
        while (res[idx] != start) ++idx;

        // Rotate the result to start from 'start'
        rotate(res.begin(), res.begin() + idx, res.end());
        return res;
    }
};
