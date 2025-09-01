class Solution {
public:
    int dp[401];
    int solve(vector<int>& nums, int n){
        if (n < 0) return 0;
        if(dp[n]!=-1){
            return dp[n];
        }

        int notake = 0+solve(nums,n-1);
        int take = nums[n]+solve(nums,n-2);
      
        return dp[n]= max(take,notake);
    }
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int n = nums.size()-1;
        return solve(nums,n);
        
    }
};