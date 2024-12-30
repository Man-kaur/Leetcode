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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;

        q.push(root);
        bool LTR = true;   // left to right
 
        while(!q.empty()){
            int size = q.size();
            vector<int> level(size);

            for(int i=0;i<size;i++){
                auto front = q.front();
                q.pop();
                int idx = LTR ? i : size - i - 1;
                level[idx] = front->val;

                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }

            res.push_back(level);
            LTR = !LTR;
        }

        return res;
    }
};