class Solution {
public:

    bool check(vector<int> arr, int mid, int days){
        int count = 1, sum = 0;

        for(int i=0; i<arr.size(); i++){
            if(sum + arr[i] > mid){
                count++;
                sum = arr[i];
            }else{
                sum += arr[i];
            }

        }

        return count <= days;
    }

    int shipWithinDays(vector<int>& arr, int days) {
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int res = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if(check(arr, mid, days)){
                res = min(res, mid);
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return res;
    }
};