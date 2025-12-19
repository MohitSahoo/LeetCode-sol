class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()== 0){
            return 0;
        }
        if(nums.size() == 1){
            return nums[0];
        }
        vector<int>dp(nums.size(),-1);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        int take =0;
        int nottake =0;
        for(int i =2;i<nums.size();i++){
            take=nums[i]+dp[i-2];
            nottake = 0 + dp[i-1];
            dp[i]=max(take,nottake);

        }
        return dp[nums.size()-1];

        
    }
};