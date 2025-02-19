class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vizz) {

        queue<int> q;
        q.push(node);
        vizz[node] = true;
        while (!q.empty()) {
            int front = q.front();
            q.pop();

            for(int i=0; i < adj[0].size(); i++){
                if(!vizz[i] && adj[front][i]==1){
                    vizz[i] = true;
                    q.push(i);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        vector<bool> vizz(isConnected.size(), false);

        int count = 0;
        for (int i = 0; i < isConnected.size(); i++) {
            if (!vizz[i]) {
                // vizz[i] = true;
                dfs(i, isConnected, vizz);
                count++;
            }
        }

        return count;
    }
};