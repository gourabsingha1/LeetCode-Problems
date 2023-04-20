class Solution {
public:
    int levelorderTraversal(TreeNode *root){
        long res = 1;
        queue<pair<TreeNode*, long>> q;
        q.push({root, 1});
        while (q.size()) {
            long t = q.size(), l = q.front().second, r;
            while(t--) {
                auto [node, ind] = q.front();
                q.pop();
                ind -= l;
                r = ind;

                if (node->left){
                    q.push({node->left, ind * 2});
                }
                if (node->right){
                    q.push({node->right, ind * 2 + 1});
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