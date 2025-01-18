class Solution {
public:
    int minimumLength(string str) {
        
        int n = str.length()-1;
        int i =0, j = n;

        while(i<j && str[i]==str[j]){
            char ch = str[i];
            while(i<=j && str[i]==ch) i++;
            while(j>=i && str[j]==ch) j--;
        } 

        return j-i+1;
    }
};