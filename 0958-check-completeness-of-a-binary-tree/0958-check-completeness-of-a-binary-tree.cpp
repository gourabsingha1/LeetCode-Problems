class Solution {
public:
    bool levelorderTraversal(TreeNode *root){
        bool res = 1;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            int n = q.size();
            bool check1 = 0, check2 = 0;
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                if(!node){
                    res = 0;
                }
                else{
                    if(!res) return 0;
                    q.push(node->left);
                    q.push(node->right);
                }
            }
        }
        return 1;
    }
    bool isCompleteTree(TreeNode* root) {
        return levelorderTraversal(root);
    }
};