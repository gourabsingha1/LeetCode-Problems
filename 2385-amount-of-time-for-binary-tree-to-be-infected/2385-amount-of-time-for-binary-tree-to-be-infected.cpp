class Solution {
public:
    unordered_map<int, vector<int>> adj;
    void dfs(TreeNode* parent, TreeNode* root) {
        if(!root) {
            return;
        }
        int u = parent->val, v = root->val;
        if(u != v) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(root, root->left);
        dfs(root, root->right);
    }
    int amountOfTime(TreeNode* root, int start) {
        dfs(root, root);
        unordered_map<int, bool> vis;
        int level = -1;
        queue<int> q;
        q.push(start);
        vis[start] = 1;
        while(q.size()) {
            int t = q.size();
            while(t--) {
                int u = q.front();
                q.pop();
                for(auto& v : adj[u]) {
                    if(!vis[v]) {
                        q.push(v);
                        vis[v] = 1;
                    }
                }
            }
            level++;
        }
        return level;
    }
};