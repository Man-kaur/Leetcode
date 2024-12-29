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
    int maxDepth(TreeNode* root) {
        queue<pair<int, TreeNode*>> q;
        if(!root) return 0;
        int level = 0;
        q.push({0, root});

        while(!q.empty()){
            auto front = q.front();
            q.pop();
            TreeNode* node = front.second;
            level = front.first;
            if(node->left) q.push({level+1, node->left});
            if(node->right) q.push({level+1, node->right});
        }

        return level+1;
    }
};