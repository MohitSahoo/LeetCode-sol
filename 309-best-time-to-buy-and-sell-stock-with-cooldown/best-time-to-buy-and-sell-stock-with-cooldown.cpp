class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        dp[0][0] = 0;           
        dp[0][1] = -1e9;  

        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= 1; j++){
                int profit = 0;
                if(j == 1){
                    if(i >= 2){
                        profit = max(-prices[i-1] + dp[i-2][0], dp[i-1][1]);
                    } else {
                        profit = max(-prices[i-1] + dp[i-1][0], dp[i-1][1]);
                    }
                } else {
                    profit = max(prices[i-1] + dp[i-1][1], dp[i-1][0]);
                }
                dp[i][j] = profit;
            }
        }
        return dp[n][0];
    }
};
