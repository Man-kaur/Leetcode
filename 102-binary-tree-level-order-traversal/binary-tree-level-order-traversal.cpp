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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(!root) return res;

        queue<pair<int, TreeNode*>> q;
        q.push({0, root});

        while(!q.empty()){
            auto front = q.front();
            q.pop();
           
           int level = front.first;
           TreeNode* node = front.second;

           if(res.size() <= level) res.push_back({});

           res[level].push_back(node->val);
           if(node->left) q.push({level+1, node->left });
           if(node->right) q.push({level+1,node->right });
        }

        return res;
    }
};