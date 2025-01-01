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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);
        if(!root) return node;
        TreeNode* cur = root;

        while(true){
            if(cur->val > val){
                if(!cur->left){
                    cur->left = node;
                    break;
                }
                cur = cur->left;
            }else{
                if(!cur->right) {
                    cur->right = node;
                    break;
                }
                cur = cur->right;

            }
        }
        return root;
    }
};