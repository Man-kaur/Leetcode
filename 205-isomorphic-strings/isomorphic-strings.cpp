class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> mps;
        unordered_map<char, int> mpt;

        for(int i=0; i<s.length(); i++){
            if(mps.find(s[i]) == mps.end()) mps[s[i]] = i;
            if(mpt.find(t[i]) == mpt.end()) mpt[t[i]] = i;

            if(mps[s[i]] != mpt[t[i]]) return false;
        }        

        return true;
    }
};