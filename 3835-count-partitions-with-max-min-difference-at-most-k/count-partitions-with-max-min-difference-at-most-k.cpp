// C++ (O(n) amortized)
// LeetCode 3578: Count Partitions With Max-Min Difference at Most K
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int MOD = 1'000'000'007;
        int n = nums.size();
        vector<int> dp(n+1, 0);      // dp[i] = ways to partition first i elements
        vector<int> pref(n+1, 0);    // pref[i] = sum_{t=0..i} dp[t]
        dp[0] = 1;
        pref[0] = 1;

        deque<int> minq, maxq; // store values (or indices) for min / max
        int l = 0;             // leftmost valid start for current right

        for (int r = 0; r < n; ++r) {
            // push nums[r] into monotonic max-queue (decreasing)
            while (!maxq.empty() && maxq.back() < nums[r]) maxq.pop_back();
            maxq.push_back(nums[r]);

            // push nums[r] into monotonic min-queue (increasing)
            while (!minq.empty() && minq.back() > nums[r]) minq.pop_back();
            minq.push_back(nums[r]);

            // shrink from left while window invalid
            while (!maxq.empty() && !minq.empty() && (maxq.front() - minq.front() > k)) {
                // remove nums[l] from queues if they are at front
                if (!maxq.empty() && maxq.front() == nums[l]) maxq.pop_front();
                if (!minq.empty() && minq.front() == nums[l]) minq.pop_front();
                ++l;
            }

            // dp[r+1] = sum_{j = l..r} dp[j] = pref[r] - pref[l-1]
            long long add = pref[r];
            if (l - 1 >= 0) add = (add - pref[l-1] + MOD) % MOD;
            dp[r+1] = int(add);
            pref[r+1] = (pref[r] + dp[r+1]) % MOD;
        }

        return dp[n];
    }
};
