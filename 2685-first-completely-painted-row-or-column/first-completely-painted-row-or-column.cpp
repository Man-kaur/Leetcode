class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        unordered_map<int, pair<int,int>> mp;

        // map to store elements -> indices
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                mp[mat[i][j]] = {i, j};
            }
        }

        // row[i] will store elements in ith row
        // col[i] will store elements in ith col
        vector<int> rowPaint(m,0);
        vector<int> colPaint(n,0);

        for(int i=0; i<arr.size(); i++){
            auto [x,y] = mp[arr[i]];   
            rowPaint[x]++;
            colPaint[y]++;

            if(rowPaint[x]==n || colPaint[y]==m) return i;
        }

        return arr.size()-1;
    }
};