class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        sort(inter.begin(), inter.end());
        vector<vector<int>> res;

        int start = inter[0][0], end = inter[0][1];

        for(int i=1; i<inter.size(); i++){
            if(inter[i][0] <= end){
                end = max(end, inter[i][1]);
            }else{
                res.push_back({start, end});
                start = inter[i][0];
                end = inter[i][1];
            }
        }

        res.push_back({start, end});

        return res;
    }
};