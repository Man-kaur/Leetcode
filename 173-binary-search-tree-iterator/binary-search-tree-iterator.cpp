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
  private:
            stack<TreeNode*> st;
            void push_all_left(TreeNode* root){
                while(root!=nullptr){
                    st.push(root);
                    root = root->left;
                }
            }
    public:
            BSTIterator(TreeNode* root){
                push_all_left(root);
            }
            int next(){
                TreeNode *new_node =st.top();
                st.pop();
                push_all_left(new_node->right);
                return new_node->val; 
            }
            bool hasNext(){
                return !st.empty();
            }

};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */