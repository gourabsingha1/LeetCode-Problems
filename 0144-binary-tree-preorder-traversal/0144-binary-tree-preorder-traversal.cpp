class Solution {
public:
        vector<int> preorderTraversal(TreeNode *root){
        vector<int> res;
        if(root == NULL){
            return res;
        }
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            root = st.top();
            st.pop();
            res.push_back(root->val);
            if(root->right){
                st.push(root->right);
            }
            if(root->left){
                st.push(root->left);
            }
        }

        return res;
    }
};