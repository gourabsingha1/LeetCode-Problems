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
            res = temp;
        }
        return res;
    }

    TreeNode* res;
    void dfs1(int n, TreeNode* root, unordered_map<int, bool>& seen) {
        if(!root) return;
        int cnt = 0;
        dfs2(cnt, root, seen);
        if(cnt == n) {
            res = root;
        }
        dfs1(n, root->left, seen);
        dfs1(n, root->right, seen);
    }

    void dfs2(int& cnt, TreeNode* root, unordered_map<int, bool>& seen) {
        if(!root) return;
        if(seen[root->val]) {
            cnt++;
        }
        dfs2(cnt, root->left, seen);
        dfs2(cnt, root->right, seen);
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        vector<int> lastLevel = levelorderTraversal(root);
        unordered_map<int, bool> seen;
        for (int i = 0; i < lastLevel.size(); i++)
        {
            seen[lastLevel[i]] = 1;
        }
        dfs1(lastLevel.size(), root, seen);
        return res;
    }
};