class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int res = 1, count = 1;

        for(int i=0; i<n-1; i++){
            if(nums[i]<nums[i+1]) count++, res = max(count, res);
            else count = 1;
        }

        count = 1;
        for(int i=0; i<n-1; i++){
            if(nums[i]>nums[i+1]) count++, res = max(count, res);
            else count = 1;
        }
        
        return res;
    }
};