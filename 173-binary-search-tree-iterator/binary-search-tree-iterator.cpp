class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    void pushAll(TreeNode* root) {
        while(root!=NULL) {
            st.push(root);
            root=root->left;
        }
    }
    
    int next() {
        TreeNode* curr= st.top();
        st.pop();
        pushAll(curr->right);
        return curr->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }

};
