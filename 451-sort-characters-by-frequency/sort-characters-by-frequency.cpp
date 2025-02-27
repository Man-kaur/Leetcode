class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        priority_queue<pair<int, char>> pq;

        for(char c: s) mp[c]++;

        for(auto &ele : mp) pq.push({ele.second, ele.first});

        string ans = "";

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            for(int i=0; i<top.first; i++) ans += top.second;
        }

        return ans;
    }
};