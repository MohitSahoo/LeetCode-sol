class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& pathVisited, vector<int>& order) {
        visited[node] = 1;
        pathVisited[node] = 1; // mark current node in recursion stack

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (!dfs(neighbor, adj, visited, pathVisited, order)) return false;
            } else if (pathVisited[neighbor]) {
                // cycle detected
                return false;
            }
        }

        pathVisited[node] = 0; // backtrack
        order.push_back(node);  // post-order
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }

        vector<int> visited(numCourses, 0);
        vector<int> pathVisited(numCourses, 0);
        vector<int> order;

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (!dfs(i, adj, visited, pathVisited, order)) return {}; // cycle detected
            }
        }

        reverse(order.begin(), order.end());
        return order;
    }
};
