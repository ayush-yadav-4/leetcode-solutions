class Disjoint {
public:
    vector<int> size, parent;
    Disjoint(int v) {
        size.resize(v, 1);
        parent.resize(v);
        for (int i = 0; i < v; i++) {
            parent[i] = i;
        }
    }

    int findparent(int u) {
        if (parent[u] == u) return u;
        return parent[u] = findparent(parent[u]);
    }

    void unionbysize(int u, int v) {
        int par_u = findparent(u);
        int par_v = findparent(v);

        if (par_u == par_v) return;
        if (size[par_u] > size[par_v]) {
            parent[par_v] = par_u;
            size[par_u] += size[par_v];
        } else {
            parent[par_u] = par_v;
            size[par_v] += size[par_u];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        Disjoint d(accounts.size());
        unordered_map<string, int> mp;

        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                if (mp.find(email) == mp.end()) {
                    mp[email] = i;
                } else {
                    d.unionbysize(mp[email], i);
                }
            }
        }

        vector<vector<string>> arr(accounts.size());
        for (auto& it : mp) {
            string email = it.first;
            int idx = it.second;
            int parent = d.findparent(idx);
            arr[parent].push_back(email);
        }

        vector<vector<string>> ans;
        for (int i = 0; i < accounts.size(); i++) {
            if (arr[i].empty()) continue;
            sort(arr[i].begin(), arr[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]); // Name
            temp.insert(temp.end(), arr[i].begin(), arr[i].end());
            ans.push_back(temp);
        }

        return ans;
    }
};
