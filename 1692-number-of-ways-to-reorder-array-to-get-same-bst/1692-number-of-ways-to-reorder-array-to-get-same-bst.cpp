class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> comb; // Pascal's triangle for combinations

    void buildComb(int n) {
        comb = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= n; ++i) {
            comb[i][0] = comb[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % MOD;
            }
        }
    }

    int dfs(vector<int>& nums) {
        if (nums.size() <= 2) return 1;

        vector<int> left, right;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[0])
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        int leftWays = dfs(left);
        int rightWays = dfs(right);

        long long ways = comb[left.size() + right.size()][left.size()];
        ways = (ways * (long long)leftWays) % MOD;
        ways = (ways * (long long)rightWays) % MOD;

        return (int)ways;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        buildComb(n);
        return (dfs(nums) - 1 + MOD) % MOD; // exclude original order
    }
};
