class Solution {
public:
    int robLinear(vector<int>& nums, int start, int end) {
        int n = end - start + 1;
        if (n == 0) return 0;
        if (n == 1) return nums[start];

        vector<int> dp(n, 0);
        dp[0] = nums[start];
        int take =0;
        int nottake =0;

        for (int i = 1; i < n; i++) {
            take = nums[start  + i];
            if(i>1){
                take +=dp[i-2];
            }
            nottake = 0+ dp[i-1];
            dp[i]=max(take,nottake);
        }
        return dp[n-1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];


        int case1 = robLinear(nums, 0, n - 2);
       
        int case2 = robLinear(nums, 1, n - 1);

        return max(case1, case2);
    }
};
