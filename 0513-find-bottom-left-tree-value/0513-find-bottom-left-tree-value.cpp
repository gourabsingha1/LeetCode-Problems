class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);
        TreeNode* curr;
        while(!q.empty()){
            curr = q.front();
            q.pop();
            if(curr->right) q.push(curr->right);
            if(curr->left) q.push(curr->left);
        }
        return curr->val;
    }
};