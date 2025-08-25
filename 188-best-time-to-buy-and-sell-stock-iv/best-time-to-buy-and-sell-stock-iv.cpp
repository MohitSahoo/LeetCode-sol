class Solution {
public:
    int maxProfit(int m, vector<int>& prices) {
        int n = prices.size();
        if(n == 0){
            return 0;
        }
        
          
        int maxk = m;
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(maxk+1, vector<int>(2, 0)));

        for (int k = 0; k <= maxk; k++) {
            dp[0][k][0] = 0;
            dp[0][k][1] = -1e9;  
        }
        for(int i =1;i<n+1;i++){
            for(int k =0;k<=maxk;k++){
                for(int j =0;j<=1;j++){
                    int profit =0;
                    if(j ==1){
                        profit = max(-prices[i-1]+dp[i-1][k][0],0+dp[i-1][k][1]);
                    }else{
                        if(k>0){
                        profit = max(prices[i-1]+dp[i-1][k-1][1] ,0+dp[i-1][k][0]);
                        }
                    }
                    dp[i][k][j]=profit;
                }
                
            }
        }
        return dp[n][maxk][0];
        
        
        
    }
};