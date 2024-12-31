class Solution {
public:
    int helper(vector<int> &dp, vector<int> days, vector<int> costs, int n) {
        if (n == days.size())
            return 0;

        if(dp[n]!=-1) return dp[n];
        // 1day pack 
        int c1 = costs[0] + helper(dp, days, costs, n+1);
        //7days pack
        int i = n;
        while(i<days.size() && days[i] < days[n]+7) i++;
        int c2 = costs[1] + helper(dp, days, costs, i) ;
        //30days pack

        i=n;
        while(i<days.size() && days[i] < days[n]+30) i++;
        int c3 = costs[2] + helper(dp, days, costs, i);

        dp[n] = min({c1, c2 , c3});
        return dp[n];
    }
    int mincostTickets(vector<int> days, vector<int> costs) {
       vector<int> dp(days.size(), -1);
       return helper(dp, days, costs, 0);
    }
};

//lemme think
// Use what you think then will worlok