class Solution {
public:
    int helper(vector<int> arr, int mid) {
        int sum = 0;

        for(int i=0; i<arr.size(); i++){
            if(arr[i] % mid == 0) sum += arr[i]/mid;
            else sum += arr[i]/mid + 1;
        }

        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1, high = *max_element(nums.begin(), nums.end());
        int res = INT_MAX;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            int sum = helper(nums, mid);
            if (sum <= threshold) {
                res = min(res, mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return res;
    }
};