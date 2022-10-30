class Solution {
public:
    int inorderTraversal(TreeNode *root, int k){
        int cnt = 0;
        stack<TreeNode*> st;
        TreeNode *curr = root;
        while(1){
            if(curr){
                st.push(curr);
                curr = curr->left;
            }
            else{
                if(st.empty()){
                    break;
                }
                curr = st.top();
                st.pop();
                cnt++;
                if(cnt == k){
                    return curr->val;
                }
                curr = curr->right;
            }
        }
        return -1;
    }
    int kthSmallest(TreeNode* root, int k) {
        return inorderTraversal(root, k);
    }
};