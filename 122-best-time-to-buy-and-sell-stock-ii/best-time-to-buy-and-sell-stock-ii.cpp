class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -1e9; 

        for (int i = 1; i <= n; i++) {
          
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i-1]);

            // holding stock today:
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i-1]);
        }

        return dp[n][0];  
    }
};
