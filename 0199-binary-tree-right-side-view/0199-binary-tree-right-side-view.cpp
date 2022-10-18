class Solution {
    public:
    vector<int> levelorderTraversal(TreeNode *root){
        vector<int> res;
        if(root == NULL){ // base case
            return res;
        }
        deque<TreeNode*> q;
        q.push_back(root);
        while (q.size()) { // in second loop, q = 2,3
            int n = q.size(); // 2
            if(!q.empty()){
                res.push_back(q.back()->val); // 2
            }
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front(); // 2
                q.pop_front();
                
                // check for left and right subtree
                if (node->left) q.push_back(node->left); // q = 3,4
                if (node->right) q.push_back(node->right); // q = 3,4,5
            }
        }
        return res;
    }

    vector<int> rightSideView(TreeNode* root) {
        return levelorderTraversal(root);
    }
};