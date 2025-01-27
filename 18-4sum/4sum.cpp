class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> res;

        sort(arr.begin(), arr.end());

        for(int i=0; i<n-3; i++){               //fixed first element
            if(i>0 && arr[i]==arr[i-1]) continue;               //handle duplicates

            for(int j=i+1; j<n-2; j++){          //fixed second element
                if(j>i+1 && arr[j]==arr[j-1]) continue;         //handle duplicates

                int left = j+1;
                int right = n-1;

                while(left<right){
                    long long sum = (long long)arr[i] + arr[j] + arr[left] + arr[right];

                    if(sum==target){
                        res.push_back({arr[i], arr[j], arr[left], arr[right]});
                        while(left < right && arr[left]==arr[left+1]) left++;
                        while(left < right && arr[right]==arr[right-1]) right--;
                        left++;
                        right--;
                    }else if(sum>target){
                        right--;
                    }else{
                        left++;
                    }
                }
            }
        }

        return res;
    }
};