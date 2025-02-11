class Solution {
public:
    string removeOccurrences(string s, string part) {
        // int n = part.length();

        // stack<char> st;

        // for(char c : s){
        //     if(!st.empty() && c == 'c'){
        //         string str = "";

        //         while(!st.empty()){

        //         }
        //     }else{
        //         st.push(c);
        //     }
        // }
        while(s.find(part) != string::npos) {
            s.erase(s.find(part), part.size());
        }
        return s;
    }
};