class Solution {
public:
    int maxScore(string s) {
        int zeroes = 0, ones=0, res=0;

        for(char c: s){
            if(c=='1') ones++;
        }

        for(int i=0;i<s.length()-1;i++){
            if(s[i]=='0') zeroes++;
            else ones--;
            res = max(res, zeroes+ones);
        }

        return res;
    }
};