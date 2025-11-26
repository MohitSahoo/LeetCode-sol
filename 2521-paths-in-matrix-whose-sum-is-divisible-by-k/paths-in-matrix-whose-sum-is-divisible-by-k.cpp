class Solution {
public:
    static const int MOD = 1000000007;
    vector<vector<vector<int>>> dp;  
    int func(vector<vector<int>>& grid, int i, int j, int sum, int k) {
     
        if (i < 0 || j < 0) {
            return 0;
        }

       
        sum = sum + grid[i][j];
        int rem = sum % k;

    
        if (i == 0 && j == 0) {
            if (rem == 0) {
                return 1;
            } else {
                return 0;
            }
        }


        int &ans = dp[i][j][rem];
        if (ans != -1) {
            return ans;
        }

        long long up = func(grid, i - 1, j, sum, k);
        long long left = func(grid, i, j - 1, sum, k);

        ans = (int)((up + left) % MOD);
        return ans;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        dp.assign(n, vector<vector<int>>(m, vector<int>(k, -1)));

       
        return func(grid, n - 1, m - 1, 0, k);
    }
};
