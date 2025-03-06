class Solution {
public:

    int solve(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &grid){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        if(grid[i][j] == 1){
           dp[i][j] = 0;
        }else{
            dp[i][j] = solve(i-1, j, dp, grid) + solve(i, j-1, dp, grid);
        }

        return dp[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(grid[0][0]==1 || grid[m-1][n-1]==1) return 0;
        if(m==1 && n==1 && grid[m-1][n-1]==0) return 1;

        vector<vector<int>> dp(m, vector<int> (n, -1));

        solve(m-1, n-1, dp, grid);

        return dp[m-1][n-1];
    }
};