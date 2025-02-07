class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> res;

        unordered_map<int, int> colors; //color->balls
        unordered_map<int, int> mp; //ball -> color

        for(auto &q : queries){
            int ball = q[0], color = q[1];

            if(mp.count(ball)){
                colors[mp[ball]]--;
                if(colors[mp[ball]]==0) colors.erase(mp[ball]); 
            }
                mp[ball] = color;
                colors[color]++;
                res.push_back(colors.size());
        }

        return res;
    }
};