class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x) 
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py)
            parent[px] = py;
    }

    vector<int> getFactors(int n) {
        vector<int> factors;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                factors.push_back(i);
                while (n % i == 0) n /= i;
            }
        }
        if (n > 1) factors.push_back(n);
        return factors;
    }

    int largestComponentSize(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        parent = vector<int>(maxVal + 1);
        iota(parent.begin(), parent.end(), 0); // initialize parent[i] = i

        for (int num : nums) {
            vector<int> factors = getFactors(num);
            for (int f : factors) {
                unite(num, f); // connect number with its prime factors
            }
        }

        unordered_map<int, int> count;
        int maxSize = 0;

        for (int num : nums) {
            int root = find(num);
            maxSize = max(maxSize, ++count[root]);
        }

        return maxSize;
    }
};
