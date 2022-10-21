class Solution {
public:
    int res = 0;
    void dfs(TreeNode *root, int rootVal){
        if(root == NULL){
            return;
        }
        if(root->val >= rootVal){
            res++;
        }
        dfs(root->left, max(rootVal, root->val));
        dfs(root->right, max(rootVal, root->val));
    }
    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        return res;
    }
};