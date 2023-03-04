class Solution {
public:
    unordered_map<int, vector<int>> adj;
    void treeToGraph(TreeNode* parent, TreeNode* root) {
        if(!root) {
            return;
        }
        int u = parent->val, v = root->val;
        if(u != v) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        treeToGraph(root, root->left);
        treeToGraph(root, root->right);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        treeToGraph(root, root);
        unordered_map<int, bool> vis;
        queue<int> q;
        q.push(target->val);
        vis[target->val] = 1, k++;
        while(q.size() && k--) {
            int t = q.size();
            while(t--) {
                int u = q.front();
                q.pop();
                if(k == 0) {
                    res.push_back(u);
                }
                for(auto& v : adj[u]) {
                    if(!vis[v]) {
                        q.push(v);
                        vis[v] = 1;
                    }
                }
            }
        }
        return res;
    }
};