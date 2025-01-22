class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> res(m, vector<int>(n, INT_MAX));
        queue<tuple<int, int, int>> q; //x, y, ht;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==1){
                    q.push({i, j, 0});
                    res[i][j] = 0;
                }
            }
        }

        int dx[]={0, 0, -1, 1};
        int dy[]={1, -1, 0, 0};

        while(!q.empty()){
            auto[x, y, ht] = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx>=0 && nx<m && ny>=0 && ny<n && res[nx][ny]==INT_MAX){
                    res[nx][ny] = ht+1;
                    q.push({nx, ny, ht+1});
                }
            }
        }
        return res;
    }
};