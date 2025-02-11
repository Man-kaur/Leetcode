class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = part.length();

        reverse(part.begin(), part.end());
        stack<char> st;

        for(char c : s){
            if(c == part[0]){
                string str = "";
                str += c;
                int i = 0;
                while(!st.empty() && i<n-1){
                    str += st.top();
                    i++;
                    st.pop();
                }
                
                if(str == part){
                continue;
                }    
                else {
                    reverse(str.begin(), str.end());
                    for(char c : str) st.push(c);
                }
                
            }else{
                st.push(c);
            }
        }

        string res = "";

        while(!st.empty()) res+=st.top(), st.pop();

        reverse(res.begin(), res.end());
        return res;
    }
};