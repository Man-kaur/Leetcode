class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        // create a dp-table
        int n = str1.size(), m = str2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

        for(int i = n-1; i >= 0; i--) {
            for(int j = m-1; j >= 0; j--) {
                if(str1[i] == str2[j]) 
                    dp[i][j] = 1 + dp[i+1][j+1];
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }

        // forming superdequence
        string s = "";

        int i = 0, j = 0;
        while(i < n && j < m) {
            if(str1[i] == str2[j]) s += str1[i], i++, j++;
            else {
                if(dp[i+1][j] >= dp[i][j+1]) s += str1[i], i++;
                else s += str2[j], j++;
            }
        }

        while(i < n) s += str1[i++];
        while(j < m) s += str2[j++];

        return s;
    }
};