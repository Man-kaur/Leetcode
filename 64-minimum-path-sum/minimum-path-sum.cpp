class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        dp[0][0] = grid[0][0];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                int left = i - 1 >= 0 ? dp[i - 1][j] : INT_MAX;
                int up = j - 1 >= 0 ? dp[i][j - 1] : INT_MAX;
                dp[i][j] = grid[i][j] + min(left, up);
            }
        }

        return dp[m - 1][n - 1];
    }
};