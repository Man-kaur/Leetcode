class Solution {
public:
    vector<vector<int>> generate(int rows) {
        vector<vector<int>> res;


        for(int i=0; i<rows; i++){
            vector<int> temp(i+1, 1);  //this will make sure the first and last ele=1

            //no need to assign val to first and last ele (1 always)
            for(int j=1; j<i; j++){
                temp[j] = res[i-1][j] +res[i-1][j-1];
            }

            res.push_back(temp);
        }

        return res;
    }
};