class Solution {
public:
    bool isDigit(char c){
        if(c>='0' && c<='9') return true;
        return false;
    }

    string clearDigits(string s) {
        stack <char> st; 

        for(char c: s){
            if(!isDigit(c)) st.push(c);
            else st.pop();
        }

        string res = "";

        while(!st.empty()){
            char c = st.top();
            res += c;
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};