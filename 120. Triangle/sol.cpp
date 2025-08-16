class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();

        
        vector<vector<int>> dp(m, vector<int>(m, 0));
        dp[0][0] = triangle[0][0];

        for (int i = 1; i < m; i++) {
            for (int j = 0; j <= i; j++) {
                int up = 1e8, diag = 1e8;

                
                if (j < i) {
                    up = triangle[i][j] + dp[i-1][j];
                }
                
                if (j > 0) {
                    diag = triangle[i][j] + dp[i-1][j-1];
                }

                dp[i][j] = min(up, diag);
            }
        }

      
        return *min_element(dp[m-1].begin(), dp[m-1].begin() + m);
    }
};
