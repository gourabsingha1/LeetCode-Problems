class Solution {
public:
    bool levelorderTraversal(TreeNode *root){
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            int n = q.size();
            bool check1 = 0, check2 = 0;
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left){
                    if(check1 || check2) return 0;
                    q.push(node->left);
                }
                else{
                    check1 = 1;
                }
                if (node->right){
                    if(check1 || check2) return 0;
                    q.push(node->right);
                }
                else{
                    check2 = 1;
                }
            }
            if(pow(2, level) != n && q.size()) return 0;
            level++;
        }
        return 1;
    }
    bool isCompleteTree(TreeNode* root) {
        return levelorderTraversal(root);
    }
};