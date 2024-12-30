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

    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        queue<pair<TreeNode* , int >> q;
        q.push({root, 0});

        map<int, int> mp;

        while(!q.empty()){
            auto front = q.front();
            q.pop();

            TreeNode* node = front.first;
            int level = front.second;

            if(mp.find(level)==mp.end()) mp[level] = node->val;

            if(node->right) q.push({node->right, level+1});
            if(node->left) q.push({node->left, level+1});
        }

        for(auto i: mp) res.push_back(i.second);

        return res;
    }
};