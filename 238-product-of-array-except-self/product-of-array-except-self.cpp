class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int count = 0;
        for(int i: nums){
            if(i!=0) product *= i;
            if(i==0) count++;
        }

        if(count>1){
            vector<int> res(nums.size(), 0);
            return res;
        }

        if(count==1){
            vector<int> res;
            for(int i=0;i<nums.size();i++){
                if(nums[i]!=0){
                    res.push_back(0);
                }else{
                    res.push_back(product);
                }
            }
            return res;
        }

        vector<int> res;
        for(int i=0;i<nums.size();i++){
                res.push_back(product/nums[i]);
        }

        return res;
    }
};