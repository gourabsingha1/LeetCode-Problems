class BSTIterator {
public:
    stack<TreeNode*> st;
    bool reverse = 0; // reverse = 1, descending order
    BSTIterator(TreeNode* root) {
        inputStack(root);
    }
    
    int next() {
        TreeNode *curr = st.top();
        st.pop();
        if(reverse){
            inputStack(curr->left); // go to left and push all the rights
        }
        else{
            inputStack(curr->right); // go to right and push all the lefts
        }
        return curr->val;
    }

    void inputStack(TreeNode* curr){
        while(curr){
            st.push(curr);
            if(reverse){
                curr = curr->right;
            }
            else{
                curr = curr->left;
            }
        }
    }
    
    bool hasNext() {
        return !st.empty();
    }
};