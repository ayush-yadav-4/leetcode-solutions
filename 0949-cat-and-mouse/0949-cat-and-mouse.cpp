class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        const int N = graph.size();
        vector<vector<vector<int>>> color(N, vector<vector<int>>(N, vector<int>(2)));
        vector<vector<vector<int>>> degree(N, vector<vector<int>>(N, vector<int>(2)));

        // Initialize degrees
        for (int m = 0; m < N; ++m) {
            for (int c = 0; c < N; ++c) {
                degree[m][c][0] = graph[m].size(); // Mouse's move
                degree[m][c][1] = graph[c].size(); // Cat's move
                if (find(graph[c].begin(), graph[c].end(), 0) != graph[c].end()) {
                    degree[m][c][1]--; // Remove move to hole for cat
                }
            }
        }

        queue<tuple<int, int, int>> q;

        // Terminal states
        for (int i = 1; i < N; ++i) {
            color[0][i][0] = 1;
            color[0][i][1] = 1;
            q.push({0, i, 0});
            q.push({0, i, 1});

            color[i][i][0] = 2;
            color[i][i][1] = 2;
            q.push({i, i, 0});
            q.push({i, i, 1});
        }

        while (!q.empty()) {
            auto [m, c, t] = q.front(); q.pop();
            int res = color[m][c][t];
            for (auto [pm, pc, pt] : getPrevStates(m, c, t, graph)) {
                if (color[pm][pc][pt] != 0) continue;
                if (res == (pt == 0 ? 1 : 2)) {
                    color[pm][pc][pt] = res;
                    q.push({pm, pc, pt});
                } else {
                    if (--degree[pm][pc][pt] == 0) {
                        color[pm][pc][pt] = (pt == 0 ? 2 : 1);
                        q.push({pm, pc, pt});
                    }
                }
            }
        }

        return color[1][2][0];
    }

    vector<tuple<int, int, int>> getPrevStates(int m, int c, int t, vector<vector<int>>& graph) {
        vector<tuple<int, int, int>> res;
        if (t == 0) {
            for (int pc : graph[c]) {
                if (pc == 0) continue;
                res.emplace_back(m, pc, 1);
            }
        } else {
            for (int pm : graph[m]) {
                res.emplace_back(pm, c, 0);
            }
        }
        return res;
    }
};
