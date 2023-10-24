// brute force

class Solution {
public:
    vector<int> levelorderTraversal(TreeNode *root){
        vector<int> res;
        if(!root){
            return res;
        }

        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            int n = q.size(), mx = INT_MIN;
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                mx = max(mx, node->val);
                
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            res.push_back(mx);
        }
        return res;
    }
    vector<int> largestValues(TreeNode* root) {
        return levelorderTraversal(root);
    }
};