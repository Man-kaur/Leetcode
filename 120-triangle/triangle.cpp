class Solution {
public:
    int helper(vector<vector<int>>& triangle, vector<vector<int>>& dp, int i,
               int j) {

        int n = triangle.size();
        if (i == n - 1 || j == n - 1)
            return dp[i][j] = triangle[i][j];

        if (dp[i][j] != INT_MAX)
            return dp[i][j];

        int down = helper(triangle, dp, i + 1, j);
        int diag = helper(triangle, dp, i + 1, j + 1);

        return dp[i][j] = triangle[i][j] + min(down, diag);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        helper(triangle, dp, 0, 0);

        return dp[0][0];
    }
};