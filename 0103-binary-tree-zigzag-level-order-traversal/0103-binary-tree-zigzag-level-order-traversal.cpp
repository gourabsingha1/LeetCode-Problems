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
            int t = q.size(), j = -1;
            vector<int> temp(t);
            while(t--)
            {
                TreeNode* node = q.front();
                q.pop();
                if(turn) j = t;
                else j++;
                temp[j] = node->val;
                if (node->left){
                    q.push(node->left);
                }
                if (node->right){
                    q.push(node->right);
                }
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