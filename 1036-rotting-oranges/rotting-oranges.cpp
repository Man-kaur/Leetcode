class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows =grid.size();
        int cols = grid[0].size();

        queue<pair<pair<int,int>,int>> q;
        int time = 0;

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == 2) q.push({{i, j},time });
            }
        }

        // up, down, left, right
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        while(!q.empty()){
            auto front = q.front();
            q.pop();

            int x = front.first.first;
            int y = front.first.second;
            int t = front.second;

            time = max(time, t);

            for(int i=0; i<4; i++){

                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx>=0 && nx<rows && ny>=0 && ny<cols && grid[nx][ny]==1) {
                    q.push({{nx, ny}, time+1});
                    grid[nx][ny]=2;
                }
            }
        }


        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == 1) return -1;
            }
        }



        return time;
    }
};