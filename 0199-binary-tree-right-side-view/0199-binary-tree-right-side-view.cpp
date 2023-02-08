class Solution {
public:
    vector<int> levelorderTraversal(TreeNode *root){
        vector<int> res;
        if(!root){
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            int t = q.size();
            for (int i = 0; i < t; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(i + 1 == t){
                    res.push_back(node->val);
                }
                if (node->left){
                    q.push(node->left);
                }
                if (node->right){
                    q.push(node->right);
                }
            }
        }
        return res;
    }
    vector<int> rightSideView(TreeNode* root) {
        return levelorderTraversal(root);
    }
};