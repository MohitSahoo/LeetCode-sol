class Solution {
public:
    void solve(int i, vector<int>& candidates, int target, int sum, vector<int>& op1, vector<vector<int>>& v) {
        if (i >= candidates.size()) {
            if (sum == target) {
                v.push_back(op1);
            }
            return;
        }
        if (sum > target) {
            return;
        }

        sum+=candidates[i];
        op1.push_back(candidates[i]);
        solve(i, candidates, target, sum , op1, v);
        sum-=candidates[i];
        op1.pop_back(); // backtrack

        // Skip the current element
        solve(i + 1, candidates, target, sum, op1, v);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> op1;
        vector<vector<int>> v;
        solve(0, candidates, target, 0, op1, v);
        return v;
    }
};
