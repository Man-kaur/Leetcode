class Solution {
public:

    int solve(int i, int j, vector<vector<int>> &dp){
        if(i==0 || j==0) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = solve(i-1, j, dp) + solve(i, j-1, dp);
    }   

    int uniquePaths(int m, int n) {
        if(m==1 || n==1) return 1;

        vector<vector<int>> dp(m, vector<int> (n, 1));
        
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};