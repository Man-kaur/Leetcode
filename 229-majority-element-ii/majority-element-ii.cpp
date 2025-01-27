class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1 = 0, ele2 = 0;
        int count1 = 0, count2 = 0;
        int n = nums.size();

        for(int i: nums){
            if(i==ele1){
                count1++;
            }else if(i==ele2){
                count2++;
            }else if(count1==0){
                ele1 = i;
                count1 = 1;
            }else if(count2==0){
                ele2 = i;
                count2 = 1;
            }else{
                count1--;
                count2--;
            }
        }

        count1 = count2 = 0;
        for(int num: nums){
            if(num==ele1) count1++;
            else if(num==ele2) count2++;
        }

        vector<int> res;
        if(count1 > n/3) res.push_back(ele1);
        if(count2 > n/3) res.push_back(ele2);

        return res;
    }
};