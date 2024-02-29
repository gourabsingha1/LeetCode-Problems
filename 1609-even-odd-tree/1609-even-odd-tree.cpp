class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(q.size()){
            int n = q.size(), prev;
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if(level % 2 == 0 && (i == 0 && node->val % 2 == 0 || i > 0 && !(prev % 2 && node->val % 2 && prev < node->val))) {
                    return 0;
                }
                if(level % 2 && (i == 0 && node->val % 2 || i > 0 && !(prev % 2 == 0 && node->val % 2 == 0 && prev > node->val))) {
                    return 0;
                }
                
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                prev = node->val;
            }
            level++;
        }
        return 1;
    }
};