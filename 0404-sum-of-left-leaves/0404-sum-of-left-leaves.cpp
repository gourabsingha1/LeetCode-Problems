class Solution {
public:
    int levelorderTraversal(TreeNode *root){
        int res = 0;
        if(root == NULL){ // base case
            return res;
        }

        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) { // in second loop, q = 2,3
            int n = q.size(); // 2
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front(); // 2
                q.pop();
                
                // check for left and right subtree
                if (node->left){
                    if(!node->left->left && !node->left->right){
                        res += node->left->val;
                    }
                    q.push(node->left); // q = 3,4
                }
                if (node->right) q.push(node->right); // q = 3,4,5
            }
        }
        return res;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return levelorderTraversal(root);
    }
};