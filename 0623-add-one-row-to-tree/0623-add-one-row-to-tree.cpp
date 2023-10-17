class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        
        int level = 1;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            int size = q.size();
            while(size--) {
                TreeNode* node = q.front();
                q.pop();
                if(level == depth - 1) {
                    TreeNode* temp = node->left;
                    node->left = new TreeNode(val);
                    node->left->left = temp;
                    q.push(temp);
                }
                else if (node && node->left){
                    q.push(node->left);
                }

                if(level == depth - 1) {
                    TreeNode* temp = node->right;
                    node->right = new TreeNode(val);
                    node->right->right = temp;
                    q.push(temp);
                }
                else if (node && node->right){
                    q.push(node->right);
                }
            }
            level++;
        }
        return root;
    }
};