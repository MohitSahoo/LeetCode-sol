class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int total = 0;
        for (int r = 0; r < m; ++r) {
            int l = 0, h = n - 1, firstNeg = n;
            while (l <= h) {
                int mid = l + (h - l) / 2;
                if (grid[r][mid] < 0) {
                    firstNeg = mid;
                    h = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            total += (n - firstNeg);
        }
        return total;
    }
};
