class Solution {
public:
    vector<int> parent;

    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void unionSet(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu != pv)
            parent[pu] = pv;
    }

    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        parent.resize(n + 1);
        for (int i = 0; i <= n; ++i)
            parent[i] = i;

        // Connect cities with common divisor > threshold
        for (int i = threshold + 1; i <= n; ++i) {
            for (int j = 2 * i; j <= n; j += i) {
                unionSet(i, j);
            }
        }

        vector<bool> result;
        for (auto& q : queries) {
            result.push_back(find(q[0]) == find(q[1]));
        }
        return result;
    }
};
