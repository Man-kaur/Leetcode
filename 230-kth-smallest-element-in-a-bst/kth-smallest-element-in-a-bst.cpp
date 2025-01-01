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
    void inorder(TreeNode* root, int &count, int k , int &res){
        if(!root) return;
        inorder(root->left ,count, k, res);
        count++;
        if(count==k){
            res = root->val;
            return;
        }
        inorder(root->right, count, k, res);
    }
    int kthSmallest(TreeNode* root, int k) {
        int res = 0;
        int count = 0;
        inorder(root, count, k, res);
        return res;
    }
};