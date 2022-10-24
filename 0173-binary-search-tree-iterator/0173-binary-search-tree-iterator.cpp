class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        while(root){
            st.push(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode *curr = st.top();
        st.pop();
        int x = curr->val;
        if(curr->right){
            curr = curr->right;
            while(curr){
                st.push(curr);
                curr = curr->left;
            }
        }
        return x;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};