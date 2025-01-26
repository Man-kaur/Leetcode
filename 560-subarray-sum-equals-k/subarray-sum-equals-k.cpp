class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int res = 0, sum = 0;
        mp[0] = 1;

        for(int &i: nums){
            sum += i;
            if(mp.count(sum-k)) res += mp[sum-k];
            mp[sum]++;
        }

        return res;
    }
};