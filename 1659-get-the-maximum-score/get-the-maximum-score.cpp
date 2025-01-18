class Solution {
private:
    const int mod = 1e9 + 7;
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        int i = 0, j = 0;
        long long sum1 = 0, sum2 = 0, res = 0;

        while (i < len1 && j < len2) {
            if (nums1[i] < nums2[j]) {
                sum1 = (sum1+nums1[i]);
                i++;
            } else if (nums1[i] > nums2[j]) {
                sum2 = (sum2+nums2[j]);
                j++;
            } else {
                res = max(sum1, sum2) + nums2[j];
                res %= mod;
                sum1 = res;
                sum2 = res;
                i++;
                j++;
            }
        }

        while (i < len1) {
            sum1 = (sum1 + nums1[i++]);
        }

        while (j < len2) {
            sum2 = (sum2 + nums2[j++]);
        }

        return max(sum1, sum2)%mod;
    }
};