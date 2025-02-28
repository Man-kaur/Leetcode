class Solution {
public:
    int helper(vector<int>& nums, vector<int>& dp, int start, int i) {
        if (i < start)
            return 0;
        if (dp[i] != -1)
            return dp[i];

        return dp[i] = max(nums[i] + helper(nums, dp, start, i - 2),
                           helper(nums, dp, start, i - 1));
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];

        vector<int> dp(n, -1);
        int a = helper(nums, dp, 1, n - 1);

        dp = vector<int>(n - 1, -1);
        int b = helper(nums, dp, 0, n - 2);

        return max(a, b);
    }
};