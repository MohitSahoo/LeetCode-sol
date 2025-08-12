class Solution {
public:
    vector<int> dp; 

    int climbStairs(int n) {
        dp.assign(n + 1, -1); 
        return solve(n);
    }

    int solve(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        if (dp[n] != -1) return dp[n];

        dp[n] = solve(n - 1) + solve(n - 2);
        return dp[n];
    }
};
