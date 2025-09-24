class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        if (iniColor == color) return image; 
        vector<vector<int>> ans = image;
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        dfs(sr, sc, ans, image, color, dr, dc, iniColor);
        return ans;
    }

    void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image,
             int newColor, int dr[], int dc[], int iniColor) {

        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();

        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m
                && image[nr][nc] == iniColor && ans[nr][nc] != newColor) {
                dfs(nr, nc, ans, image, newColor, dr, dc, iniColor);
            }
        }
    }
};
