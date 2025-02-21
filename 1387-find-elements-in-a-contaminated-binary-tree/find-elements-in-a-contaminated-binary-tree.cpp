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
class FindElements {
public:

    unordered_set<int> st;
    FindElements(TreeNode* root) {
        check(root, 0);
    }
    
    void check(TreeNode* root, int val){
        if(!root) return;
        root->val = val;
        st.insert(root->val);
        if(root->left){
            check(root->left, root->val*2 + 1);
        }
        if(root->right){
            check(root->right, root->val*2 + 2);
        }
    }

    bool find(int target) {
        return st.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */