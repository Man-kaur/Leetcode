/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void fill(TreeNode* root, map<int, map<int, multiset<int>>> &mp, int level, int col){
        if(!root) return;

        mp[col][level].insert(root->val);
        fill(root->left, mp, level+1, col-1);
        fill(root->right, mp, level+1, col+1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res;
        map<int, map<int, multiset<int>>> mp;
        fill(root, mp, 0, 0);

        for(auto i: mp){
            vector<int> col;
            for(auto level: i.second){
                col.insert(col.end(), level.second.begin(), level.second.end());
            }
        res.push_back(col);
        }

        return res;
    }
};