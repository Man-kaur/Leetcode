class Solution {
private:
    int mod = 1e9 + 7;
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> pref(n, 0);
        int count=0 , odds=0, evens=1;
        int sum = 0;

        for(int i=0; i<n; i++){
            sum += arr[i];
            if(sum%2 != 0){
                count = (count + evens)%mod;
                odds++;
            }else{
                count = (count + odds)%mod;
                evens++;
            }
        }

        return count%mod;
    }
};