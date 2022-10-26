class Solution {
public:
    void levelorderTraversal(TreeNode *root){
        if(!root){
            return;
        }

        vector<int> dummy;
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            int n = q.size();
            vector<int> temp;
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                if(level&1){
                    node->val = dummy[n - 1 - i];
                }

                if (node->left){
                    temp.push_back(node->left->val);
                    q.push(node->left);
                }
                if (node->right){
                    temp.push_back(node->right->val);
                    q.push(node->right);
                }
            }
            dummy = temp;
            level++;
        }
        return;
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        levelorderTraversal(root);
        return root;
    }
};