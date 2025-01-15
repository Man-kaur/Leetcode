class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        vector<bool> res(n, true);
        res[0] = res[1] = false;

        for(int i=2;i*i<n;i++){
            if(res[i]){
                for(int j=i*i; j<n; j+=i) res[j] = false;
            }
        }
        int count = 0;
        for(bool i: res){
            if(i) count++;
        }

        return count;
    }
};