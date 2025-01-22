class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size();
        int n = mat[0].size();

        int low = 0, high=m-1;
        int row;
        while(low <= high){

            int mid = low + (high-low)/2;
            if(mat[mid][0]<=target && mat[mid][n-1]>=target){
                row = mid;
                break;
            }else if(mat[mid][0]>target) high = mid-1;
            else low = mid+1;

        }


        int start = 0, end = n-1;

        while(start <= end){
            int mid = start + (end-start)/2;

            if(mat[row][mid]==target) return true;
            else if(mat[row][mid]>target) end= mid-1;
            else start = mid+1;
        }

        return false;
    }
};