class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int sum = INT_MIN, res = 1;
        if(!root){
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (q.size()) {
            int t = q.size(), cur = 0;
            while(t--) {
                TreeNode* node = q.front();
                q.pop();
                cur += node->val;
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            level++;
            if(cur > sum){
                res = level;
                sum = cur;
            }
        }
        return res;
    }
};