class Solution {
public:
    int digitSum(int num){
        int sum = 0;

        while(num>0){
            sum += num % 10;
            num /= 10;
        }

        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int> mp;  // digit sum -> ind

        int res = 0;

        for(int i=0; i<nums.size(); i++){
            int sum = digitSum(nums[i]);

            if(mp.count(sum)){
                res = max(res, nums[i] + nums[mp[sum]]);
                if(nums[mp[sum]] < nums[i]) mp[sum] = i;
            }else{
                mp[sum] = i;
            }

        }

        return res==0 ? -1 : res;
    }
};