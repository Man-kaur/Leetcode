class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

       int left=0;
        int right=arr.size();
        while(left<right){
            int mid=(left+right)/2;
            if(arr[mid]-mid-1<k){
                left=mid+1;

            }else{
                right=mid;
            }

        }
        return left+k;
    }
};