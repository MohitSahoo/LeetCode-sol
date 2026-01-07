class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxEnding = 0, minEnding = 0;
        int maxSum = 0, minSum = 0;

        for (int x : nums) {
            maxEnding = max(x, maxEnding + x);
            minEnding = min(x, minEnding + x);

            maxSum = max(maxSum, maxEnding);
            minSum = min(minSum, minEnding);
        }

        return max(maxSum, abs(minSum));
    }
};
