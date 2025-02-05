class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int count = 0;
        int n = s1.length();
        unordered_map<char, int> mp;

        for(int i=0; i<n; i++){
            if(s1[i] != s2[i]) count++, mp[s1[i]]=i;
        }

        for(int i=0; i<n; i++){
            if(s1[i] != s2[i]){
                swap(s1[i], s1[mp[s2[i]]]);
                break;
            }
        }
        if((count == 0 || count==2) && s1==s2) return true;
        return false;
    }
};