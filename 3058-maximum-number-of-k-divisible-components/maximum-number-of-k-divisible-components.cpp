class Solution {
public:
    vector<vector<int>> adj;
    int ans = 0, k;

    int dfs(int node, int parent, vector<int>& values) {
        long long sum = values[node];

        for (int child : adj[node]) {
            if (child == parent) continue;
            sum += dfs(child, node, values);
        }

        if (sum % k == 0) {
            ans++;
            return 0;
        }
        return sum % k;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int kk) {
        k = kk;
        adj.resize(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, -1, values);
        return ans;
    }
};
