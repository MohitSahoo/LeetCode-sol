class Solution {
public:

    int maxProfit(vector<int>& prices) {
        if(prices.size()==0){
            return 0;
        }
        int dp[prices.size()+1][2];
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for(int i =1;i<prices.size();i++){
            for(int buy = 0;buy<=1;buy++){
                int profit =0;
                if(buy){
                profit = max(-prices[i]+dp[i-1][0] , 0 + dp[i-1][1]);
                }else{
                    profit = max(prices[i]+dp[i-1][1],0+dp[i-1][0]);
                }
                dp[i][buy]=profit;

            }
        }
        return dp[prices.size()-1][0];

        
    }
};