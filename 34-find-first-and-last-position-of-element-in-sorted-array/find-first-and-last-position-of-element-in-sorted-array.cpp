class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {

        // if(arr.size()==1 && arr[0]==target) return {0, 0};

        int l = -1, h = -1;
        bool flag = true;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]==target){
                if(flag) l = i, h = i, flag = false;
                else h = i;
            }
        }

        return {l, h};
    }
};