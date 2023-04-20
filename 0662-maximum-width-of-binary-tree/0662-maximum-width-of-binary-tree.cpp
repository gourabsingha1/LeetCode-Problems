class Solution {
public:
    int levelorderTraversal(TreeNode *root){
        int res = 1;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        while (q.size()) {
            int t = q.size(), l = q.front().second, r;
            while(t--) {
                TreeNode* node = q.front().first;
                int ind = q.front().second - l;
                q.pop();
                r = ind;

                if (node->left){
                    q.push({node->left, 1LL * ind * 2});
                }
                if (node->right){
                    q.push({node->right, 1LL * ind * 2 + 1});
                }
            }
            res = max(res, r + 1);
        }
        return res;
    }
    int widthOfBinaryTree(TreeNode* root) {
        return levelorderTraversal(root);
    }
};