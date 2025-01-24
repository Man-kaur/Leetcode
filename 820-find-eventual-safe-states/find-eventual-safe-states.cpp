class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int nodes = graph.size();
        vector<int> outdegree(nodes, 0);
        vector<vector<int>> rev(nodes);
        queue<int> q;

        for(int i=0; i<nodes; i++){
            for(auto j : graph[i]){
                rev[j].push_back(i);
            }
            outdegree[i] = graph[i].size();
        }

        int index = 0;
        for(auto i: outdegree){
            if(i==0){
                q.push(index);
            }
            index++;
        }

        vector<int> res;
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            res.push_back(front);

            for(int i: rev[front]){
                outdegree[i]--;
                if(outdegree[i]==0) q.push(i);
            }
        }
        
        sort(res.begin(), res.end());
        return res;
    }
};