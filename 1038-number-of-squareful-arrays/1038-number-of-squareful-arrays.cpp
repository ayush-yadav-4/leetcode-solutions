class Solution {
public:
    int count = 0;
    unordered_map<int, vector<int>> graph;
    unordered_map<int, int> freq;

    bool isPerfectSquare(int x) {
        int r = sqrt(x);
        return r * r == x;
    }

    void dfs(int node, int remaining, unordered_map<int, int>& freq) {
        if (--freq[node] < 0) {
            freq[node]++;
            return;
        }

        if (remaining == 0) {
            count++;
            freq[node]++;
            return;
        }

        for (int next : graph[node]) {
            if (freq[next] > 0)
                dfs(next, remaining - 1, freq);
        }

        freq[node]++;
    }

    int numSquarefulPerms(vector<int>& nums) {
        int n = nums.size();

        // Count frequency of each number
        for (int num : nums) freq[num]++;

        // Build graph where edge exists if sum of two nums is a perfect square
        for (auto& [a, _] : freq) {
            for (auto& [b, __] : freq) {
                if (isPerfectSquare(a + b)) {
                    graph[a].push_back(b);
                }
            }
        }

        // Start DFS from each unique number
        for (auto& [num, _] : freq) {
            dfs(num, n - 1, freq);
        }

        return count;
    }
};
