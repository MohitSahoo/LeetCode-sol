class Solution {
public:
    int n;
    vector<vector<int>> dp;  // dp[i][mod] = best sum from i with this remainder

    int func(int i, int mod, vector<int>& nums) {
        // Base case: processed all elements
        if (i == n) {
            // Only valid if final sum % 3 == 0
            if (mod == 0) return 0;
            return INT_MIN;  // invalid, impossible state
        }

        // Already computed
        if (dp[i][mod] != INT_MIN) return dp[i][mod];

        // Option 1: don't take nums[i]
        int notake = func(i + 1, mod, nums);

        // Option 2: take nums[i]
        int newMod = (mod + nums[i]) % 3;
        int takeRest = func(i + 1, newMod, nums);

        int take = INT_MIN;
        if (takeRest != INT_MIN) { 
            // only valid if remaining part is valid
            take = nums[i] + takeRest;
        }

        return dp[i][mod] = max(take, notake);
    }

    int maxSumDivThree(vector<int>& nums) {
        n = nums.size();
        dp.assign(n, vector<int>(3, INT_MIN));

        int ans = func(0, 0, nums);
        if (ans < 0) return 0;  // in case nothing is valid, but 0 is always valid
        return ans;
    }
};
