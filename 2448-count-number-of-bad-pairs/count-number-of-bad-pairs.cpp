class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, long long> mp;
        long long n = nums.size();
        long long good_pairs = 0;

        for(int i=0; i<n; i++){
            int diff = nums[i]  - i;
            good_pairs += mp[diff];
            mp[diff]++;
        }

        long long total_pairs = (long long) (n*(n-1))/2;
        return total_pairs - good_pairs;
    }
};