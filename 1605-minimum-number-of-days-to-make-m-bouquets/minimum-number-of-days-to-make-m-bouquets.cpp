class Solution {
public:
    bool check(vector<int> arr, int mid, int m, int k) {
        int count = 0, bq = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= mid) {
                count++;
                if (count == k)
                    bq++, count = 0;
            } else {
                count = 0;
            }
        }

        return bq >= m;
    }

    int minDays(vector<int>& arr, int m, int k) {
        int n = arr.size();
        if ((long)m * k > n)
            return -1;
        int low = 1, high = *max_element(arr.begin(), arr.end());
        int maxi = high;
        int res = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(arr, mid, m, k)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return res ;
    }
};