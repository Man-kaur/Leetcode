class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        dp[0][0] = triangle[0][0];

        for(int i=1; i<n; i++){
            for(int j=0; j<i+1; j++){
                int up = dp[i-1][j];
                int diagUp = j-1>=0 ? dp[i-1][j-1] : INT_MAX;

                dp[i][j] = triangle[i][j] + min(up, diagUp);
            }
        }

        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};