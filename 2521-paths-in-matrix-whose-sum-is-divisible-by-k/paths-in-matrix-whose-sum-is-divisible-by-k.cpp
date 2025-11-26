class Solution {
public:
    static const int MOD = 1000000007;
    vector<vector<vector<int>>> dp;   // dp[i][j][rem]

    int func(vector<vector<int>>& grid, int i, int j, int sum, int k) {
        // out of bounds
        if (i < 0 || j < 0) {
            return 0;
        }

        // include current cell in sum
        sum = sum + grid[i][j];
        int rem = sum % k;

        // base case: reached (0,0)
        if (i == 0 && j == 0) {
            if (rem == 0) {
                return 1;
            } else {
                return 0;
            }
        }

        // memo check
        int &ans = dp[i][j][rem];
        if (ans != -1) {
            return ans;
        }

        // recursive calls: move up and left
        long long up = func(grid, i - 1, j, sum, k);
        long long left = func(grid, i, j - 1, sum, k);

        ans = (int)((up + left) % MOD);
        return ans;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        // dp[i][j][rem] initialized to -1
        dp.assign(n, vector<vector<int>>(m, vector<int>(k, -1)));

        // start from bottom-right with sum = 0
        return func(grid, n - 1, m - 1, 0, k);
    }
};
