class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int max_sum = INT_MIN, current_sum = 0, min_sum = INT_MAX;

        for (int num : nums) {
            current_sum += num;
            max_sum = max(max_sum, current_sum);
            if(current_sum < 0) current_sum = 0;
        }

        current_sum = 0;
        for(int num: nums){
            current_sum += num;
            min_sum = min(min_sum, current_sum);
            if(current_sum > 0) current_sum = 0;
        }

        return max(max_sum, abs(min_sum));
    }
};