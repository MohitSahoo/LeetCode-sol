class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        const int INF = 1e9;

        vector<vector<int>> dp(n+1, vector<int>(amount+1, INF));

       
        for (int i = 0; i <= n; i++) dp[i][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int t = 1; t <= amount; t++) {
                int notTake = dp[i-1][t];
                int take = INF;
                if (coins[i-1] <= t) take = 1 + dp[i][t - coins[i-1]];
                dp[i][t] = min(notTake, take);
            }
        }

        if(dp[n][amount]>= INF){
            return -1;
        }else{
            return dp[n][amount];
        }
    }
};
