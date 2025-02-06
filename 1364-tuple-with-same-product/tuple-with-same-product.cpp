class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> mp;

        int count = 0; 
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++){
                int prod = nums[i]*nums[j];
                mp[prod]++;
            }
        }

        for(auto &ele : mp){
            int f = ele.second;
            count += (f)*(f-1)/2 * 8;
        }

        return count;
    }
};