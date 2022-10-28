class Solution {
public:
    bool levelOrder(TreeNode *root){
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(q.size()){
            int n = q.size();
            int prev = INT_MIN;
            if(level&1){
                prev = INT_MAX;
            }
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if(!(level&1) && !(node->val&1 && prev < node->val) || level&1 && !(!(node->val&1) && prev > node->val)){
                    return 0;
                }
                prev = node->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            level++;
        }
        return 1;
    }
    bool isEvenOddTree(TreeNode* root) {
        return levelOrder(root);
    }
};