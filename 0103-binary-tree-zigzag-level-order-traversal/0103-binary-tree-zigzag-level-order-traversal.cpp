class Solution {
public:
    vector<vector<int>> levelorderTraversal(TreeNode*& root){
        vector<vector<int>> res;
        if(!root){
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool turn = 0;
        while (q.size()) {
            int t = q.size();
            vector<int> temp;
            while(t--) {
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if (node->left){
                    q.push(node->left);
                }
                if (node->right){
                    q.push(node->right);
                }
            }
            if(turn){
                reverse(temp.begin(), temp.end());
            }
            res.push_back(temp);
            turn = !turn;
        }
        return res;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        return levelorderTraversal(root);
    }
};