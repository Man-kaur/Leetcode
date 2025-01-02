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
class BSTIterator {
public:
    vector<int> numbers;
    int i=0;
    BSTIterator(TreeNode* root) {
        traversal(root);
    }
    void traversal(TreeNode* root){
        if(!root) return;
        traversal(root->left);
        numbers.push_back(root->val);
        traversal(root->right);
    }

    int next() {
        return numbers[i++];
    }
    
    bool hasNext() {
        if(i<numbers.size()) return true;
        else return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */