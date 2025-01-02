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
    bool find(TreeNode* root, unordered_set<int> &seen, int k){
        if(!root) return false;
        int curr = root->val;

        if(seen.count(k-curr)) return true;
        seen.insert(curr);
        return find(root->left, seen, k) || find(root->right, seen, k);

    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> seen;
        return find(root, seen, k);
    }
};