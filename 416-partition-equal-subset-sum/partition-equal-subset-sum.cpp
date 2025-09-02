class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum =0;
        for(int i =0;i<nums.size();i++){
            sum+=nums[i];
        }
        int k =0;
        if(sum %2 ==1){
            return false;
        }else{
            k = sum/2;
        }
        int n = nums.size();
        vector<vector<bool>>dp(n,vector<bool>(k+1,false));
        for(int i =0;i<n;i++){
            dp[i][0]=true;
        }
        if(nums[0]<=k){
            dp[0][nums[0]]=true;
        }
        for(int i =1;i<n;i++){
            for(int j =1;j<k+1;j++){
                int notake = dp[i-1][j];
                int take = false;
                if(nums[i]<=j){
                    take = dp[i-1][j-nums[i]];
                }
                dp[i][j]=take||notake;
            }
        
        }
        return dp[n-1][k];
        
    }
};