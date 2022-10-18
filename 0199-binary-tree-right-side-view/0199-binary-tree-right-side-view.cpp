class Solution {
    public:
    vector<int> levelorderTraversal(TreeNode *root){
        vector<int> res;
        if(root == NULL){ // base case
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) { // in second loop, q = 2,3
            int n = q.size(); // 2
            for (int i = 0; i < n; i++) {
                if(i == n-1){
                    res.push_back(q.front()->val); // 2
                }
                TreeNode* node = q.front(); // 2
                q.pop();
                
                // check for left and right subtree
                if (node->left) q.push(node->left); // q = 3,4
                if (node->right) q.push(node->right); // q = 3,4,5
            }
        }
        return res;
    }

    vector<int> rightSideView(TreeNode* root) {
        return levelorderTraversal(root);
    }
};