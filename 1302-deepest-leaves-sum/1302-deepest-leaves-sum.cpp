class Solution {
public:
    int levelorderTraversal(TreeNode *root){
        int res = 0;
        if(!root){
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            int t = q.size();
            res = 0;
            while(t--) {
                TreeNode* node = q.front();
                q.pop();
                res += node->val;
                if (node->left){
                    q.push(node->left);
                }
                if (node->right){
                    q.push(node->right);
                }
            }
        }
        return res;
    }
    int deepestLeavesSum(TreeNode* root) {
        return levelorderTraversal(root);
    }
};