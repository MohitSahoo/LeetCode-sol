class Solution {
public:
    
    int fib(int n) {
        int dp[31];
        memset(dp,0,sizeof(dp));
        dp[0]=0;
        dp[1]=1;
        for(int i =2;i<n+1;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];

        
    }
};