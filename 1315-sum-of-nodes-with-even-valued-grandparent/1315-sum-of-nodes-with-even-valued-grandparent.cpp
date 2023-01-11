class Solution {
public:
    void dfs(int parent, int grandParent, TreeNode* root, int &res){
        if(!root) return;
        if(grandParent % 2 == 0) res += root->val;
        dfs(root->val, parent, root->left, res);
        dfs(root->val, parent, root->right, res);
    }
    int sumEvenGrandparent(TreeNode* root) {
        int res = 0;
        dfs(-1, -1, root, res);
        return res;
    }
};