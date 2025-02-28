class Solution {
    vector<vector<int>> dp;
    int f(string& text1, string& text2, int i, int j) {
        if(i == text1.size() || j == text2.size()) return 0;

        // check
        if(dp[i][j] != -1) return dp[i][j];

        // same
        if(text1[i] == text2[j]) 
            return dp[i][j] = 1 + f(text1, text2, i+1, j+1);
        return dp[i][j] = max(f(text1, text2, i+1, j), f(text1, text2, i, j+1));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        dp.assign(n, vector<int> (m, -1));
        return f(text1, text2, 0, 0);
    }
};