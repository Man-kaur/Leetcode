class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> res;
        sort(arr.begin(), arr.end());  // sorting is necessary to apply 2 pointer

        for(int k=0; k<n-2; k++){
            if(k>0 && arr[k]==arr[k-1]) continue; // handle duplicates
            int i = k+1;
            int j = n-1;
            int target = 0 - arr[k];
            while(i<j){
                int sum = arr[i] + arr[j];
                if(sum < target){
                    i++;
                }else if(sum > target){
                    j--;
                }else{
                    res.push_back({arr[k], arr[i], arr[j]});
                    while(i<j && arr[i]==arr[i+1]) i++;  // handle duplicates
                    while(i<j && arr[j]==arr[j-1]) j--;     //handle duplicates
                    i++;
                    j--;
                }
            }
        }

        return res;
    }
};