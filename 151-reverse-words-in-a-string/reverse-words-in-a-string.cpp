class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;

        string temp = "";
        for (char c : s) {
            if (c == ' ') {
                if (temp.size() >= 1)
                    words.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }
        if (temp.size() >= 1)
            words.push_back(temp);

        string res;
        reverse(words.begin(), words.end());

        for (string str : words)
            res += " " + str;

        res = res.substr(1);
        return res;
    }
};