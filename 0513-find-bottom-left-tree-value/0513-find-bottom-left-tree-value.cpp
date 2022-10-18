class Solution {
public:
    int levelorderTraversal(TreeNode *root){
        int res;
        if(!root){
            return res;
        }

        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                if(!i){
                    res = node->val;
                }
                
                // check for left and right subtree
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return res;
    }
    int findBottomLeftValue(TreeNode* root) {
        return levelorderTraversal(root);
    }
};